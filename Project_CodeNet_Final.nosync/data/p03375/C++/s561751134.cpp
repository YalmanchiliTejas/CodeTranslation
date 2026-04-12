#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const int N=3010,M=1000010;
int P;
const int inf=0x3f3f3f3f;
const int INF=0xcfcfcfcf;
const double eps=1e-6,pi=asin(1)*2;
inline ll read();
#define cmax(a,b) a=max(a,b)
#define cmin(a,b) a=min(a,b)
inline int ADD(int a,int b) { return a+b>=P?a+b-P:a+b; }
inline int MINUS(int a,int b) { return a-b<0?a-b+P:a-b; }
#define plus(a,b) a=ADD(a,b)
#define minus(a,b) a=MINUS(a,b)
#define mul(a,b) a=(a*(b))%P
#define mem(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define mp(x,y) make_pair(x,y)

int n;
inline int quickmi(int x,int n,int p=P)
{
	int res=1;
	for(;n;n>>=1)
	{
		if(n&1) res=1ll*res*x%p;
		x=1ll*x*x%p;
	}
	return res;
}

int S[N][N];
int C[N][N];

inline void init(int n=3005)
{
	S[0][0]=1;
	for(int i=0;i<=n;i++)
	{
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=ADD(C[i-1][j-1],C[i-1][j]),
			S[i][j]=ADD(S[i-1][j-1],1ll*S[i-1][j]*j%P);
	}
/*
	for(int i=0;i<=5;i++)
	{
		for(int j=0;j<=i;j++) cerr<<S[i][j]<<" ";
		cerr<<"\n";
	}
//*/
}

#ifdef FILE
char buf[1<<25],*p1=buf,*p2=buf;
#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<25,stdin),p1==p2)?EOF:*p1++
#endif
inline ll read()
{
	ll s=0;
	bool flag=false;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') flag=true;
	for(;'0'<=ch&&ch<='9';ch=getchar()) s=(s<<3)+(s<<1)+(ch^'0');
	if(flag) return -s;
	return s;
}

int main()
{
#ifdef FILE
	freopen(FILE ".in","r",stdin);
	freopen(FILE ".out","w",stdout);
#endif
	n=read(),P=read();
	init();
	int ans=0;
	for(int i=0;i<=n;i++)
	{
		int sum=0,mi1=quickmi(2,quickmi(2,n-i,P-1)),mi2=quickmi(2,n-i);
		for(int j=0,tmp=1;j<=i;j++,tmp=1ll*tmp*mi2%P)
			plus(sum,1ll*S[i+1][j+1]*tmp%P);
//		cerr<<i<<" "<<sum<<" "<<C[n][i]<<" "<<mi1<<"\n";
		sum=1ll*sum*C[n][i]%P*mi1%P;
		if(i&1) minus(ans,sum);
		else plus(ans,sum);
	}
	printf("%d\n",ans);
	return 0;
}