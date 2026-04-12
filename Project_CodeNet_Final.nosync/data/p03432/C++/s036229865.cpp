//Zory-2020
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// typedef __int128 ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define edge pair<int,int>
#define FR first
#define SE second
#define MP make_pair
#define PB push_back
#define vc vector
#define db double
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define bin(x) (1ll<<(x))
#define fo(i,l,r) for(int i=(l),I=(r);i<=I;i++)
#define fd(i,r,l) for(int i=(r),I=(l);i>=I;i--)
#define mem(x,val) memset(x,val,sizeof x)
#define Swap(a,b,n) for(int I=0;I<=n;I++) swap(a[I],b[I])
#define PC __builtin_popcountll
#ifdef DEBUG
	#define debug(A,args...) fprintf(stderr,A,##args)
#else
	#define debug(A,args...)
#endif
#define deb debug("line %d\n",__LINE__)
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
	void GG(){puts("No");exit(0);}

	const db eps=1e-8;
	const int INF=0x3f3f3f3f;
	const int MOD=998244353;
	int mm(const int x){return x>=MOD?x-MOD:x;}
	template<typename T> void add(T &x,const int &y){x=(x+y>=MOD?x+y-MOD:x+y);}
	ll qpower(ll x,ll e,int mod=MOD){ll ans=1;while(e){if(e&1)ans=ans*x%mod;x=x*x%mod;e>>=1;}return ans;}
	ll invm(ll x){return qpower(x,MOD-2);}
	const int MM=1e6+10;
	ll fac[MM],facinv[MM],Inv[MM];ll C(int n,int m){return n<0 or m<0 or n<m?0:fac[n]*facinv[m]%MOD*facinv[n-m]%MOD;}
	void PRE()
	{
		fac[0]=1;fo(i,1,MM-1) fac[i]=fac[i-1]*i%MOD;
		facinv[MM-1]=invm(fac[MM-1]);fd(i,MM-1,1) facinv[i-1]=facinv[i]*i%MOD;
		Inv[1]=1;fo(i,2,MM-1) Inv[i]=(MOD-MOD/i)*Inv[MOD%i]%MOD;
	}

	namespace PP//全家桶板子
	{
		const int LN=1<<19;int inv[LN+1];
		struct NTT
		{
			vc<int> w[30];NTT(){inv[1]=1;for(int i=2;i<=LN;i++) inv[i]=ll(MOD-MOD/i)*inv[MOD%i]%MOD;
				for(int i=1;i<=20;i++) {w[i].resize(bin(i));w[i][0]=1;int pp=qpower(3,(MOD-1)/bin(i));for(int j=1;j<bin(i-1);j++) w[i][j]=1ll*w[i][j-1]*pp%MOD;}
			}
			int R[LN];inline void DFT(int A[],int lg,int op=0)
			{
				int m=bin(lg);assert(m<=LN);if(op) reverse(A+1,A+m);
				for(int i=1;i<m;i++){R[i]=(R[i>>1]>>1)|((i&1)<<(lg-1));if(R[i]<i)swap(A[i],A[R[i]]);}
				for(int ln=1,lgg=1;ln<m;ln<<=1,lgg++) for(int st=0;st<m;st+=2*ln) for(int k=0;k<ln;k++)
					{int t=1ll*w[lgg][k]*A[st+ln+k]%MOD;A[st+ln+k]=mm(A[st+k]+MOD-t);A[st+k]=mm(A[st+k]+t);}
			}
		}ntt;
		int _A[LN],_B[LN],_C[LN],M;
		struct P//此结构体内函数选择性写
		{
			vc<int> a;int n;void rs(int nn){a.resize(n=nn);}P(){rs(M);}
			int& operator [] (int x){return a[x];}
			friend const P operator * (P a,const int &b) {for(int i=0;i<a.n;i++) a[i]=(ll)a[i]*b%MOD;return a;}
			inline void dft(int _A[],int lg,int ln){for(int i=0;i<bin(lg);i++)_A[i]=(i<min(ln,n)?a[i]:0);ntt.DFT(_A,lg);}
			inline void idft(int _A[],int lg,int ln){ntt.DFT(_A,lg,1);rs(ln);for(int i=0;i<ln;i++)a[i]=1ll*_A[i]*inv[bin(lg)]%MOD;}
			const P Mul(P b,int ln=M)
			{
				int lg=ceil(log2(ln+ln-1)),m=bin(lg);dft(_A,lg,ln);b.dft(_B,lg,ln);
				for(int i=0;i<m;i++) _B[i]=1ll*_A[i]*_B[i]%MOD;b.idft(_B,lg,ln);return b;
			}
			const P operator * (const P b) {return Mul(b);}
		};
		void Inv(P &a,P &b,int ln=M)
		{
			if(ln==1){b.rs(1);b[0]=invm(a[0]);return;}Inv(a,b,(ln+1)/2);
			int lg=ceil(log2(ln+ln-1)),m=bin(lg);a.dft(_A,lg,ln);b.dft(_B,lg,ln);
			for(int i=0;i<m;i++) _B[i]=(2+MOD-1ll*_B[i]*_A[i]%MOD)*_B[i]%MOD;b.idft(_B,lg,ln);
		}
		P Ji(P a){a.rs(a.n+1);for(int i=a.n-1;i>=1;i--)a[i]=1ll*a[i-1]*inv[i]%MOD;a[0]=0;return a;}
		P Dao(P a){for(int i=0;i<a.n-1;i++)a[i]=1ll*a[i+1]*(i+1)%MOD;a.rs(a.n-1);return a;}
		P Ln(P &a,int ln=M){P b;Inv(a,b,ln);return Ji(Dao(a).Mul(b,ln-1));}
		void Exp(P &a,P &b,int ln=M)
		{
			if(ln==1){b.rs(1);b[0]=1;return;}Exp(a,b,(ln+1)/2);
			P pp=Ln(b,ln);for(int i=0;i<ln;i++) pp[i]=mm(a[i]+MOD-pp[i]);pp[0]++;
			int lg=ceil(log2(ln+ln-1)),m=bin(lg);pp.dft(_A,lg,ln);b.dft(_B,lg,ln);
			for(int i=0;i<m;i++) _B[i]=1ll*_A[i]*_B[i]%MOD;b.idft(_B,lg,ln);
		}
		void Sqrt(P &a,P &b,int ln=M)
		{
			if(ln==1){b.rs(1);b[0]=1;return;}Sqrt(a,b,(ln+1)/2);P tmp=b*2,c;Inv(tmp,c,ln);
			int lg=ceil(log2(ln+ln-1)),m=bin(lg);a.dft(_A,lg,ln);b.dft(_B,lg,ln);c.dft(_C,lg,ln);
			for(int i=0;i<m;i++) _A[i]=ll((ll)_B[i]*_B[i]+_A[i])%MOD*_C[i]%MOD;b.idft(_A,lg,ln);
		}
		P Rev(P a){reverse(a.a.begin(),a.a.end());return a;}
		P Inv(P a,int ln=M){P b;Inv(a,b,ln);return b;}
		P Div(const P &a,const P &b){return Rev(Rev(a).Mul( Inv(Rev(b),a.n-b.n+1),a.n-b.n+1 ) );}

		P Mul2(P a,P b){M=a.n+b.n-1;return a*b;}
		P DandC(vc<P> &A,int l,int r)
		{
			if(l==r) return A[l];
			int mid=(l+r)/2;
			return Mul2(DandC(A,l,mid),DandC(A,mid+1,r));
		}
	};
	const int N=8e3+10;
	//------------------FIXED------------------
	int dp[N][N];using namespace PP;
	void main()
	{
		int m=qread(),n=qread();dp[0][0]=1;PRE();
		fo(i,1,n)
		{
			//fo(j,0,m) fo(ad,1,m-j) add(dp[i][j+ad], dp[i-1][j]*C(j+ad+2,ad+2)%MOD );
			M=m+1;P A,B;fo(j,0,m) A[j]=dp[i-1][j]*facinv[j]%MOD;fo(j,1,m) B[j]=facinv[j+2];
			A=A*B;fo(j,0,m) dp[i][j]=A[j]*fac[j+2]%MOD;

			fo(j,0,m) add(dp[i][j], dp[i-1][j]*(C(j,2)+j+1)%MOD );
		} int ans=0;fo(j,0,m) add(ans, dp[n][j]*C(m,j)%MOD );write2(ans);
	}
};//变量重名！
signed main()
{
	//freopen("wind.in","r",stdin);
	//freopen("wind.out","w",stdout);

	#ifdef DEBUG
	freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	#endif
	mine::main();
	debug("\n---------------------Zory---------------------\nTime: %.2lf s",1.0*clock()/CLOCKS_PER_SEC);
}
