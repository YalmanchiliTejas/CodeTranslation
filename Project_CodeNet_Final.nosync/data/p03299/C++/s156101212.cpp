#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const int N=1010,M=1000010,P=1e9+7;
const int inf=0x3f3f3f3f;
const int INF=0xcfcfcfcf;
const db eps=1e-9,pi=asin(1)*2;
inline ll read();
#define cmax(a,b) a=max(a,b)
#define cmin(a,b) a=min(a,b)
inline int ADD(int a,int b) { return a+b>=P?a+b-P:a+b; }
inline int MINUS(int a,int b) { return a-b<0?a-b+P:a-b; }
#define plus(a,b) a=ADD(a,b)
#define minus(a,b) a=MINUS(a,b)
#define mul(a,b) a=(1ll*a*(b))%P
#define mem(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define mp(x,y) make_pair(x,y)

inline int quickmi(int x,int n)
{
	int res=1;
	for(;n;n>>=1)
	{
		if(n&1) mul(res,x);
		mul(x,x);
	}
	return res;
}

int n,cnt=0;
int h[N],f[N];
int dp1[N],dp2[N],dp3[N];
inline int solve(int l,int r,int hfa)
{
	if(l>r) return 0;
	int id=++cnt,minn=inf,num=0,lst=l;
//	cerr<<id<<" "<<l<<" "<<r<<"\n";
	for(int i=l;i<=r;i++)
	{
		if(h[i]==minn) num++;
		if(h[i]<minn) minn=h[i],num=1;
	}
	dp1[id]=quickmi(2,minn-hfa);
	dp2[id]=quickmi(2,num);
	dp3[id]=MINUS(dp1[id],2);
	for(int i=l;i<=r+1;i++)
	{
		if(h[i]==minn||i>r)
		{
			int son=solve(lst,i-1,minn);
			lst=i+1;
			if(!son) continue;
			mul(dp1[id],dp1[son]);
			mul(dp2[id],ADD(dp1[son],dp2[son]));
			mul(dp3[id],dp1[son]);
		}
	}
	plus(dp2[id],dp3[id]);
	return id;
}

#ifdef FILE
const int RS=1<<20;
char buf[RS],*p1=buf,*p2=buf;
#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,RS,stdin),p1==p2)?EOF:*p1++
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
	n=read();
	for(int i=1;i<=n;i++) h[i]=read();
	dp1[0]=1;
	printf("%d\n",dp2[solve(1,n,0)]);
/*
	cerr<<"dp1: \n";
	for(int i=1;i<=cnt;i++) cerr<<dp1[i]<<" ";
	cerr<<"\n";
	cerr<<"dp2: \n";
	for(int i=1;i<=cnt;i++) cerr<<dp2[i]<<" ";
	cerr<<"\n";
	cerr<<"dp3: \n";
	for(int i=1;i<=cnt;i++) cerr<<dp3[i]<<" ";
	cerr<<"\n";
//*/
	return 0;
}