#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,u) for(int i=start[u];i;i=e[i].next)
#define fi first
#define se second
#define mkr(a,b) make_pair(a,b)
#define SZ(A) ((int)A.size())
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
inline int read()
{
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch) && ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
	return ~f?s:-s;
}

const int maxn=(1<<14)+20;
const int mod=998244353;
const int MAX=1<<14;

inline int power(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)ans=(ll)ans*a%mod;
		b>>=1;
		a=(ll)a*a%mod;
	}
	return ans;
}

int jc[maxn],jcn[maxn],inv[maxn];
int W[maxn];

int n,m;

inline void prepare()
{
	jc[0]=jc[1]=jcn[0]=jcn[1]=inv[1]=1;
	REP(i,2,MAX)jc[i]=(ll)i*jc[i-1]%mod,inv[i]=(ll)(mod-mod/i)*inv[mod%i]%mod,jcn[i]=(ll)jcn[i-1]*inv[i]%mod;
	W[0]=1; W[1]=power(3,(mod-1)/MAX);
	REP(i,2,MAX-1)W[i]=(ll)W[i-1]*W[1]%mod;
}

inline int C(int n,int m){ if(n<m || m<0)return 0; return 1ll*jc[n]*jcn[m]%mod*jcn[n-m]%mod;}

inline void FFT(int *p,int n,int op)
{
	static int rev[maxn];
	int l=0; while(1<<l<n)l++;
	REP(i,1,n-1)rev[i]=(rev[i>>1]>>1)|((i&1)<<l-1);
	REP(i,1,n-1)if(i<rev[i])swap(p[i],p[rev[i]]);
	for(int i=1;i<n;i<<=1)
		for(int j=0,w=MAX/(i<<1);j<n;j+=i<<1)
			for(int k=0;k<i;k++)
			{
				int x=p[j+k],y=(ll)W[w*k]*p[i+j+k]%mod;
				p[j+k]=(x+y)%mod;
				p[i+j+k]=(x-y+mod)%mod;
			}
	if(op==-1)
	{
		REP(i,0,n-1)p[i]=(ll)p[i]*inv[n]%mod;
		reverse(p+1,p+n);
	}
}

inline void debug()
{
	int A[8]={1,2,3,4,5,0,0,0},B[8]={2,3,4,5,6,0,0,0},C[8];
	FFT(A,8,1); FFT(B,8,1);
	REP(i,0,7)C[i]=(ll)A[i]*B[i]%mod;
	FFT(C,8,-1);
	REP(i,0,7)cerr<<C[i]<<" "; cerr<<endl;
}

inline void init()
{
	n=read();m=read();
}

int dp[320][maxn];

inline void doing()
{
	dp[0][0]=1;
	int N=1;
	while(N<=(2*n))N<<=1;
	REP(i,1,m)
	{
		static int A[maxn],B[maxn];
		memset(A,0,sizeof(int)*N); memset(B,0,sizeof(int)*N);
		REP(j,0,n)A[j]=(ll)dp[i-1][j]*jcn[j]%mod;
		REP(j,1,n)B[j]=jcn[j+2];
		FFT(A,N,1); FFT(B,N,1);
		REP(j,0,N-1)A[j]=(ll)A[j]*B[j]%mod;
		FFT(A,N,-1);
		REP(j,0,n)dp[i][j]=((ll)A[j]*jc[j+2]+(ll)dp[i-1][j]*(C(j+1,2)+1))%mod;
	}
	int ans=0;
	REP(j,0,n)ans=(ans+(ll)dp[m][j]*C(n,j))%mod;
	printf("%d\n",ans);
}

int main()
{
	prepare();
	debug();
	init();
	doing();
	return 0;
}
