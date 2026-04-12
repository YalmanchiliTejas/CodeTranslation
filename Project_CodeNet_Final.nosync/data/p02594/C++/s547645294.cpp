#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds; 

#define ff          first
#define ss          second
#define ll          int64_t
#define ld          long double
#define nl          cout<<"\n"
#define dbg(x)      cerr<<#x<<" = "<<x<<"\n"
#define dbg2(x,y)   cerr<<#x<<" = "<<x<<"   "<<#y<<" = "<<y<<"\n"
#define all(v)      v.begin(),v.end()
#define mset(a,v)   memset((a),(v),sizeof(a))
#define forn(i,a,b) for(int64_t i=int64_t(a);i<int64_t(b);++i)
#define forb(i,a,b) for(int64_t i=int64_t(a);i>=int64_t(b);--i)
#define fastio()    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> 

#define mod         1000000007
#define mod2        998244353 
#define inf         1000000000000007
#define pi          3.14159265358979323846

template<typename T,typename U> static inline void amin(T &x,U y)                   {if(y<x)x=y;}
template<typename T,typename U> static inline void amax(T &x,U y)                   {if(x<y)x=y;}  
template<class L,class R> ostream& operator<<(ostream& out,pair<L,R> &p)            {return out<<"("<<p.ff<<", "<<p.ss<<")";}
template<class T> ostream& operator<<(ostream& out,vector<T> &v)                    {out<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())out<<", ";out<<*it;}return out<<"]";}
template<class T> ostream& operator<<(ostream& out,deque<T> &v)                     {out<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())out<<", ";out<<*it;}return out<<"]";}
template<class T> ostream& operator<<(ostream& out,set<T> &s)                       {out<<"{";for(auto it=s.begin();it!=s.end();++it){if(it!=s.begin())out<<", ";out<<*it;}return out<<"}";}
template<class L,class R> ostream& operator<<(ostream& out,map<L,R> &m)             {out<<"{";for(auto it=m.begin();it!=m.end();++it){if(it!=m.begin())out<<", ";out<<*it;}return out<<"}";}

ll count_digits(ll n)   {ll dig=floor(log10(n)+1);return dig;}
ll mpow(ll x,ll y,ll p) {ll r=1;x=x%p;while(y>0){if(y&1)r=(r*x)%p;y=y>>1;x=(x*x)%p;}return r;} 
string dec_bin_32(ll n) {string s;for(ll i=31;i>=0;i--){ll k=n>>i;s+=(k&1)?'1':'0';}return s;} 
string dec_bin_64(ll n) {string s;for(ll i=63;i>=0;i--){ll k=n>>i;s+=(k&1)?'1':'0';}return s;} 
ll mod_inv(ll a,ll m)   {ll m0=m,y=0,x=1;if(m==1)return 0;while(a>1){ll q=a/m,t=m;m=a%m,a=t;t=y;y=x-q*y;x=t;}if(x<0)x+=m0;return x;} 
/* const ll MAXN=10000007;ll spf[MAXN+5];vector<ll> prime; */
/* void sieve(ll n)        {forn(i,2,MAXN+1)spf[i]=i;for(ll i=2;i*i<=n;i++)if(spf[i]==i)for(ll j=i*i;j<=n;j+=i)if(spf[j]==j)spf[j]=i;forn(i,2,MAXN+1)if(spf[i]==i)prime.push_back(i);} */

//-------------------------------L_I_Erq34-------------------------------

int main()
{
	fastio();
	ll z,n,m,t,k,i,j,l,d,h,r;
	cin>>n;
	if(n>=30)
		cout<<"Yes\n";
	else
		cout<<"No\n";
	cerr<<"\nTime elapsed: "<<1000*clock()/CLOCKS_PER_SEC<<"ms\n";
	return 0;
}
