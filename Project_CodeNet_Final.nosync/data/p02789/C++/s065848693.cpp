//Zory-2020
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// typedef __int128 ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define FR first
#define SE second
#define MP make_pair
#define PB push_back
#define vc vector
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define bin(x) (1ll<<(x))
#define fo(i,l,r) for(int i=(l),I=(r);i<=I;i++)
#define fd(i,r,l) for(int i=(r),I=(l);i>=I;i--)
#define mem(x,val) memset(x,val,sizeof x)
#define Swap(a,b,n) for(int I=0;I<=n;I++) swap(a[I],b[I])
#define PC __builtin_popcountll
#ifdef DEBUG
#define DD 1
#else
#define DD 0
#endif
#define Debug if(DD) printf("line %d\n",__LINE__)
#define deb(x) if(DD) cerr<<#x<<'='<<x<<endl
#define debug if(DD) printf
namespace mine
{
	ll qread()
	{
		ll ans=0,f=1;char c=getchar();
		while(c<'0' or c>'9') {if(c=='-')f=-1;c=getchar();}
		while('0'<=c and c<='9') ans=ans*10+c-'0',c=getchar();
		return ans*f;
	}
	void write(ll num){if(num<0) putchar('-'),num=-num;if(num>=10) write(num/10);putchar('0'+num%10);}
	void write1(ll num){write(num);putchar(' ');}
	void write2(ll num){write(num);putchar('\n');}
	template<typename T>inline bool chmax(T&a,const T&b){return a<b?a=b,1:0;}
	template<typename T>inline bool chmin(T&a,const T&b){return a>b?a=b,1:0;}
	ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
	bool IN(ll x,ll l,ll r){return l<=x and x<=r;}
	void gg1(){write2(-1);exit(0);}
	void gg2(){puts("NO");exit(0);}
	
	const double eps=1e-8;
	const int INF=0x3f3f3f3f;
	const int MOD=1e9+7;
	int mm(const int x){return x>=MOD?x-MOD:x;}
	template<typename T> void add(T &x,const int &y){x=(x+y>=MOD?x+y-MOD:x+y);}
	ll qpower(ll x,ll e,int mod=MOD){ll ans=1;while(e){if(e&1)ans=ans*x%mod;x=x*x%mod;e>>=1;}return ans;}
	ll invm(ll x){return qpower(x,MOD-2);}
	const int N=1e6+10;
	
	int a[N],mx[N];
	int dec[N];
	void main()
	{
		int n=qread(),m=qread();
		if(n==m) puts("Yes"); else puts("No");
	}
};//变量重名！
signed main()
{
	#ifdef DEBUG
	//freopen("a.in","r",stdin);
	freopen("z.txt","r",stdin);
	#endif
	srand(time(0));
	mine::main();
	if(DD) cerr<<"Time: " <<1.0*clock()/CLOCKS_PER_SEC<<"s";
}