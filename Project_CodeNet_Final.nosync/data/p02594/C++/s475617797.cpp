/*
* John Wick is a man of
* focus, commitment & sheer will
*/
#include<bits/stdc++.h>
using namespace std;
// -----------------<fast IO>------------------
#define thisIsSpeed		ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FLSH 			fflush(stdout)
#define fileIO(name) \
    freopen(name".in", "r", stdin); \
    freopen(name".out", "w", stdout);
#define PRECISIOn(x) 	cout << fixed << setprecision(x);
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
#define in(b,a)         ( (b).fpos(a) != (b).end())
// -----------------<TypeDef Start>------------------
typedef long double ld;
typedef int ll;
typedef unsigned long long ull;
typedef vector<ll> vi;
typedef map<ll,ll> mii;
// -----------------<Constants>------------------
const int mAXn = 1000005;
const int SQRTn = 1003;
const int LOGn = 22;
const double PI=acos(-1);
const ll InF=1e9;
const int mOD = 1000000009;
const int FmOD = 998244353;
const double eps = 1e-9;
// -----------------<modular Arithmetic>------------------
template<typename T> T gcd(T a, T b)
	{return(b?__gcd(a,b):a);}
template<typename T> T lcm(T a, T b)
	{return(a*(b/gcd(a,b)));}
template<typename T> T add(T a, T b, T c = mOD)
	{T res=a+b;return(res>=c?res-c:res);}
template<typename T> T mod_neg(T a, T b, T c = mOD)
	{T res;if(abs(a-b)<c)res=a-b;else res=(a-b)%c;return(res<0?res+c:res);}
template<typename T> T mul(T a, T b, T c = mOD)
	{ll res=(ll)a*b;return(res>=c?res%c:res);}
inline ll mulmod(ll a,ll b, ll m = mOD)
	{ll q = (ll)(((ld)a*(ld)b)/(ld)m);ll r=a*b-q*m;if(r>m)r%=m;if(r<0)r+=m;return r;}
template<typename T>T expo(T e, T n)
	{T x=1,p=e;while(n){if(n&1)x=x*p;p=p*p;n>>=1;}return x;}
template<typename T>T power(T e, T n, T m = mOD)
	{T x=1,p=e;while(n){if(n&1)x=mul(x,p,m);p=mul(p,p,m);n>>=1;}return x;}
template<typename T>T extended_euclid(T a, T b, T &x, T &y)
	{T xx=0,yy=1;y=0;x=1;while(b){T q=a/b,t=b;b=a%b;a=t;t=xx;xx=x-q*xx;x=t;t=yy;yy=y-q*yy;y=t;}return a;}
template<typename T>T mod_inverse(T a, T n = mOD)
	{T x,y,z=0;T d=extended_euclid(a,n,x,y);return(d>1?-1:mod_neg(x,z,n));}
// ------------------nCr---------------------------
/*
ll modInverse(ll n, ll p){return power(n, p-2);}
ll nCr(ll n, ll r, ll p=mOD){if (r==0) return 1;ll fac[n+1];fac[0]=1;for(lli=1;i<=n;i++)fac[i]=fac[i-1]*i%p;
	return (fac[n]*modInverse(fac[r],p)%p*modInverse(fac[n-r], p)%p)%p;}
*/
//-----------------sieve--------------------------
/*
//bool C[mAXn];
ll C[mAXn]={0};
vi V1;
void sieve(){
	ll ans=1;
    ll i,j;
    for(i=2;i<mAXn;i++){if(!C[i] && i<20){
		ans*=i;
        // V1.pb(i);
        for(j=2*i;j<mAXn;j=j+i){C[j]=true;}}}
        cout<<ans<<endl;
}
*/  
//-----------------custom structuree----------------
/*
struct cus{
	ll x,y,pos;
	//string str;
}b[200000];
*/
//-----------------custom compare---------------------
/*
bool compare(cus i1, cus i2){ 
	return i1.x < i2.x;
}

bool compare2(cus i1, cus i2){ 
    if(i1.y != i2.y)
		return i1.y > i2.y;
	else return i1.x >= i2.x;
}
*/
// --------------------------------------------------</TEmPLATE>--------------------------------------------------

void mainn(){
	ll z=0, k=0, t=0, n=0, x=0, m=0, curr=0, num=0, n1=0, n2=0, n3=0, n4=0, i=0 , j=0;
	ll root=0, sum=0, diff=0, q=0, choice=0, d=0, len=1, beg=0, end=0, pos=0, cnt=0;
	ll lo=0, hi=0, mid=0, ans=0;
	bool flag = false;
	string s1, s2, s3, str;
	char ch='a', ch1, ch2, ch3, *ptr;
	double dub=0;
	////////////////////////////////////////////////////////////////////////////////////////////////////////////
	cin >> n;
	if(n>=30)cout<<"Yes";
	else cout<<"No";
}

int main(){
	thisIsSpeed;
	int t=1;
	//cin>>t;
	while(t--){
		mainn();
	}
	return 0;
}
