#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
 
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3") 
#pragma GCC optimization ("unroll-loops")
 
// #include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
// const ll RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
// gp_hash_table<int, int> table;
 
#define ll  long long
#define vii vector< ll >
#define pb push_back
#define pii pair<ll,ll>
#define ppi pair<pii,ll>
#define all(x) x.begin(),x.end()
#define S second
#define F first
#define ins insert
#define ld long double
#define lp(l,r) for(i=l;i<=r;++i)
 
#define lpj(l,r) for(j=l;j<=r;++j)
#define lpr(l,r) for(i=r;i>=l;--i)
#define lprj(l,r) for(j=r;j>=l;--j)
 
#define swap(a,b){ auto _t=a;a=b,b=_t;}
#define flush() cout.flush()
#define popcount __builtin_popcount
#define die() return 0;
#define sz() size() 


 
 
#define TRACE
 
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif
 
#define MD          1000000007
#define M 			100011
#define LN             14
#define fftmod      998244353
#define EPS         (double)1e-10
 
long long  md=MD;
ll inf=1e18;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); 
 
 
inline ll exp(ll a,ll b){if(a==0&&b==0)return 1ll;if(a==0)return 0ll;ll r=1LL;while(b>0){if(b&1){r=(r%md)*(a%md);r=(r+md)%md;}b/=2;a=(a%md)*(a%md);a=(a+md)%md;}return (r+md)%md;}
ll gcd(ll a,ll b){if(b==0)return a;if(a==0)return b;return gcd(b,a%b);}
inline ll poww(ll a,ll b){ll r=1LL;while(b>0){if(b&1)r=r*a;b/=2;a=a*a;}return (ll)r;}
 
using cd=complex<double>;
const double PI=acos(-1);
 
inline ll rand(ll l,ll r){
    return l+rng()%(r-l+1);
 
}


int B[2*M];

ll get(ll x){
	ll r=0;
	for(;x>=1;x-=x&-x)r+=B[x];
		return r;
}
ll up(ll x,ll val){
	for(;x<2e5;x+=x&-x)B[x]+=val;
}



int main(){
 
     
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
 
   // ifstream fin("input.txt");ofstream fout("outut.txt");
    ll t,i,j,m,n,s,z,k,p;string s1,s2;ll q;ll x,y;
    cin>>n;
    vii v;
    lp(1,n)cin>>x,v.pb(x);
    map<ll,ll> h;
    for(auto x:v)h[x];
    k=1;
	for(auto x:h)h[x.F]=k++;
	for(i=0;i<v.sz();++i)v[i]=h[v[i]];
	ll ans=0;
	for(i=0;i<v.sz();++i){
		x=0,p=2e5;
		// trace(v[i]);
		if(get(v[i]-1)==0){
			++ans;
			up(v[i],1);continue;

		}
		for(;p>=1;p/=2){
			while(x+p<v[i]&&get(x+p)<get(v[i]-1))x+=p;
		}
		// trace(x)
		++x;
			up(x,-1);
			up(v[i],1);





	}
	cout<<ans<<"\n";




}

