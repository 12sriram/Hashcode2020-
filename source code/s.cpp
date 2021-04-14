#include<bits/stdc++.h>
#define lld      long
#define mp       make_pair
#define pb       push_back
#define ff       first
#define ss       second
#define pll      pair<lld,lld>
#define pii      pair<int,int>
#define vll      vector<lld>
#define vii      vector<int>
#define umap     unordered_map
#define lb       lower_bound
#define ub       upper_bound
#define all(x)   x.begin(),x.end()
#define sort1(x) sort(x,greater<int>())
#define rep(i,a,b) for(i = a; i < b; i++)
#define fio      ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;

namespace forever {
    template<class type1,class type2>
        inline istream &operator>>(istream &in,pair<type1,type2> &p)
        {
            in>>p.ff>>p.ss;
            return in;
        }
    template<class type1,class type2>
        inline ostream &operator<<(ostream &o,pair<type1,type2> &p)
        {
             o<<"("<<p.ff<<","<<p.ss<<")";
            return o;
        } 
    template<class type>
        inline ostream &operator<<(ostream &o,vector<type> &v)
        {
            for(int i=0;i<v.size();i++)
                o<<v[i]<<" ";
            return o;    
        }
    template<class t>
        inline istream &operator>>(istream &in,vector<t> &p)
        {
            for(auto & x : p)
                in >> x;
            return in;
        }
    struct custom_hash {
        static uint64_t splitmix64(uint64_t x) {
            x += 0x9e3779b97f4a7c15;
            x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
            x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
            return x ^ (x >> 31);
        }
        size_t operator()(uint64_t x) const {
            static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
            return splitmix64(x + FIXED_RANDOM);
        }
    };
}
using namespace forever;

umap<lld,lld,custom_hash> sob; // scores_of_books

struct library{
    lld lib_id,no_books,sdays,per_day;
    vector<lld> ids; // ids of books in library
    long double pref_val;
    lld total_score;
    library(lld a,lld b,lld c,lld e,vector<lld> &d){
        no_books = a;
        sdays = b;
        per_day = c;
        ids = d;
        lib_id = e;
        total_score = 0;
        for(lld x: d){
            total_score += sob[x];
        }
        pref_val = double((total_score * per_day)/double(sdays));
    }
};
struct compare_lib{
    bool operator() (library ob1,library ob2){
            return ob1.pref_val < ob2.pref_val;
    }    
};

bool sortby(pll a, pll b){
    if(a.ss != b.ss)
        return a.ss > b.ss;
    return a.ff < b.ff;    
}

int main()
{
	fio; 	
	#ifndef ONLINE_JUDGE 
	freopen("sip.txt","r",stdin);
   	freopen("sout.txt","w",stdout);
	#endif
    
    lld i,sc;
    lld tno_books,no_lib,no_days;
    cin >> tno_books  >>  no_lib >> no_days;
    for(i=0;i<tno_books;i++){
        cin >> sc;
        sob[i] = sc;
    }
    priority_queue<library,vector<library>,compare_lib> q;
    
    for(i=0;i<no_lib;i++){
        lld te1,te2,te3;
        cin >> te1 >> te2 >> te3;
        vll a(te1);
        cin >> a;
        q.push(library(te1,te2,te3,i,a));
    }
    
    lld j,curr_time = 0; 
    vector<vll> ans;
    umap<lld,bool,custom_hash> seen;
    while(!q.empty() && !(curr_time > no_days) ){
        library l = q.top();
        q.pop();
        vll x;
        x.pb(l.lib_id);
        lld ts = 0;
        curr_time += l.sdays;
        vector<pll> v;
        for(j=0;j<l.ids.size();j++){
            v.pb( { l.ids[j] , sob[l.ids[j]] } );
        }
        sort(all(v),sortby);
        lld cnt = 0;
        for(j=0;j<v.size();j++){
            if(!seen[v[j].ff]){
                cnt++;
                if(cnt == l.per_day){
                    cnt = 0;
                }           
                x.pb(v[j].ff);
                seen[v[j].ff] = true;
            }	
        }
	if(x.size() == 1)
		x.pb(l.ids[0]);
        ans.pb(x);
    }
    cout << ans.size() << "\n";
    for(i=0;i<ans.size();i++){
            cout << ans[i][0] << " " << (ans[i].size()-1) << "\n";
            for(j=1;j<ans[i].size();j++){
                cout << ans[i][j] << " ";
            }
            cout << "\n";
    }
	return 0;
}
