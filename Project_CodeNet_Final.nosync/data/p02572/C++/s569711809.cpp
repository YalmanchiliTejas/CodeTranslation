/*
* John Wick is a man of
* focus, commitment & sheer will
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>  
#include <functional>

using namespace __gnu_pbds;
using namespace std;

// -----------------<fast IO>------------------
#define Speed			ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FLSH 			fflush(stdout)
#define fileIO(name) \
    freopen(name".in", "r", stdin); \
    freopen(name".out", "w", stdout);
#define PRECISION(x) 	cout << fixed << setprecision(x);
#define endl 			"\n"
// -----------------<Container manipulation / traversal macros>------------------
#define pb	 			push_back
#define sz(x) 			((int)((x).size()))
#define all(x) 			(x).begin(),(x).end()
#define rep(i,n) 		for(int (i)=0;(i)<(n);(i)++)
#define forn(i,a,b) 	for(int (i)=(a);(i)<=(b);(i)++)
#define ford(i,a,b) 	for(int (i)=(b);(i)>=(a);(i)--)
#define fill(l,a)		memset((l) , (a) , sizeof(l))
#define ss				second
#define ff 				first
// -----------------<Some common useful functions>------------------
#define checkbit(n,b)   ( (n >> b) & 1)
#define in(b,a)         ( (b).find(a) != (b).end())
// -----------------<TypeDef Start>------------------
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vi;
typedef map<ll,ll> mii;
typedef pair<ll,ll> pii;
// --------------<Declaring ordered_set>---------------------- 
/* tree <data_type , null_type(set) or mapped_type(map) , 
 * 		comparison basis for two fncs , tree_type , metadata>
 * find_by_order(k):iterator to kth element
 * order_of_key(k):# of items less than k
*/
typedef tree<long long int, null_type, less<long long int>, rb_tree_tag,  
            tree_order_statistics_node_update>  
    ordered_set;  
// -----------------<Constants>------------------
const int MAXN = 1000005;
const int SQRTN = 1003;
const int LOGN = 22;
const double PI=acos(-1);
const int INF=1e9;
const int MOD = 1e9+7;
const int FMOD = 998244353;
const double eps = 1e-9;
// -----------------<Modular Arithmetic>------------------
template<typename T> T gcd(T a, T b)
	{return(b?__gcd(a,b):a);}
template<typename T> T lcm(T a, T b)
	{return(a*(b/gcd(a,b)));}
template<typename T> T add(T a, T b, T c = MOD)
	{T res=a+b;return(res>=c?res-c:res);}
template<typename T> T mod_neg(T a, T b, T c = MOD)
	{T res;if(abs(a-b)<c)res=a-b;else res=(a-b)%c;return(res<0?res+c:res);}
template<typename T> T mul(T a, T b, T c = MOD)
	{ll res=(ll)a*b;return(res>=c?res%c:res);}
inline ll mulmod(ll a,ll b, ll m = MOD)
	{ll q = (ll)(((ld)a*(ld)b)/(ld)m);ll r=a*b-q*m;if(r>m)r%=m;if(r<0)r+=m;return r;}
template<typename T>T expo(T e, T n)
	{T x=1,p=e;while(n){if(n&1)x=x*p;p=p*p;n>>=1;}return x;}
template<typename T>T power(T e, T n, T m = MOD)
	{T x=1,p=e;while(n){if(n&1)x=mul(x,p,m);p=mul(p,p,m);n>>=1;}return x;}
template<typename T>T extended_euclid(T a, T b, T &x, T &y)
	{T xx=0,yy=1;y=0;x=1;while(b){T q=a/b,t=b;b=a%b;a=t;t=xx;xx=x-q*xx;x=t;t=yy;yy=y-q*yy;y=t;}return a;}
template<typename T>T mod_inverse(T a, T n = MOD)
	{T x,y,z=0;T d=extended_euclid(a,n,x,y);return(d>1?-1:mod_neg(x,z,n));}
// ------------------nCr---------------------------
/*
ll modInverse(ll n, ll p){return power(n, p-2);}
ll fac[MAXN+1];
void factorial(ll n=MAXN, ll p=MOD){fac[0]=1;for(ll i=1;i<=n;i++)fac[i]=fac[i-1]*i%p;}
ll nCr(ll n, ll r, ll p=MOD){if (r==0) return 1;
	return (fac[n]*modInverse(fac[r],p)%p*modInverse(fac[n-r], p)%p)%p;}
*/
//-----------------sieve--------------------------
/*
//bool C[MAXN];
ll C[MAXN]={0};
vi V1;
void sieve(){
	ll ans=1;
    ll i,j;
    for(i=2;i<MAXN;i++){if(!C[i] && i<20){
		ans*=i;
        // V1.pb(i);
        for(j=2*i;j<MAXN;j=j+i){C[j]=true;}}}
        cout<<ans<<endl;
}
*/  
//-----------------custom structuree----------------
/*
struct cus{
	ll x,y;
	//string str;
};
*/
//-----------------custom compare---------------------
/*
bool compare(cus i1, cus i2){ 
    if(i1.x != i2.x)
		return i1.x < i2.x;
	else return i1.y < i2.y;
}
*/
// --------------------------------------------------</TEMPLATE>--------------------------------------------------

void mainn(){
	ll n;
	cin>>n;
	ll a[n],sum=0,ans=0;
	rep(i,n){
		cin>>a[i];
		sum=add(sum,a[i]);
	}
	rep(i,n){
		sum=mod_neg(sum,a[i]);
		ans=add(ans,mul(a[i],sum));
	}
	cout<<ans<<endl;
}
	
int main(){
	Speed;
	int t=1;
	//cin>>t;
	while(t--){
		mainn();
	}
	return 0;
}
