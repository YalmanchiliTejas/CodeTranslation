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
bool DD=0;
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
 
	const int INF=0x3f3f3f3f;
	const int MOD=1e9+7;
	int mm(const int x){return x>=MOD?x-MOD:x;}
	template<typename T> void add(T &x,const int &y){x=(x+y>=MOD?x+y-MOD:x+y);}
	ll qpower(ll x,ll e,int mod=MOD){ll ans=1;while(e){if(e&1)ans=ans*x%mod;x=x*x%mod;e>>=1;}return ans;}
	ll invm(ll x){return qpower(x,MOD-2);}
	const int N=3e6+10;

	pii b[N];
	int cnt[N];set<int> ok;
	void main()
	{
		int n=qread();int mi0=INF,mi1=INF,mx0=0,mx1=0;
		fo(i,1,n)
		{
			int x=qread(),y=qread();b[i*2-1]={x,i},b[i*2]={y,i};
			if(x>y)swap(x,y);chmin(mi0,x),chmax(mx0,x);chmin(mi1,y),chmax(mx1,y);
		}
		ll ans=1ll*(mx0-mi0)*(mx1-mi1);
		sort(b+1,b+n+n+1);
		if(b[1].SE!=b[n+n].SE or b[1].FR==b[2].FR or b[n+n-1].FR==b[n+n].FR)//有办法同侧
		{
			if(b[1].SE==b[n+n].SE and b[1].FR==b[2].FR) swap(b[1],b[2]);
			if(b[1].SE==b[n+n].SE and b[n+n-1].FR==b[n+n].FR) swap(b[n+n-1],b[n+n]);
			for(int l=2,r=1;;l++)
			{
				while(r+1<n+n and sz(ok)<n) {++r,cnt[b[r].SE]++;if(cnt[b[r].SE]==1) ok.insert(b[r].SE); }
				debug("l=%d r=%d\n",l,r);
				if(sz(ok)<n) break;chmin(ans, 1ll*(b[n+n].FR-b[1].FR)*(b[r].FR-b[l].FR) );
				cnt[b[l].SE]--;if(!cnt[b[l].SE]) ok.erase(b[l].SE);
			}
		}write(ans);
	}
};//(ans+MOD)%MOD
signed main()
{
	//freopen("a.in","r",stdin);
	srand(time(0));
	mine::main();
}