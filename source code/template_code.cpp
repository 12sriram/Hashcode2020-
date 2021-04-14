#include<bits/stdc++.h>
#define lld      long long
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
int main()
{
	fio; 	
	#ifndef ONLINE_JUDGE
    	freopen("sip.txt","r",stdin);
   	//freopen("sout.txt","w",stdout);
    	#endif
    
    
	return 0;
}
