#include<bits/stdc++.h>
#define db double
#define RE register
#define ll long long
#define P 1000000007
#define INF 1000000000
#define get(x) x=read()
#define PLI pair<ll,int>
#define PII pair<int,int>
#define pb(x) push_back(x)
#define ull unsigned long long
#define put(x) printf("%d\n",x)
#define getc(a) scanf("%s",a+1)
#define putl(x) printf("%lld\n",x)
#define rep(i,x,y) for(RE int i=x;i<=y;++i)
#define fep(i,x,y) for(RE int i=x;i>=y;--i)
#define go(x) for(int i=link[x],y=a[i].y;i;y=a[i=a[i].next].y)
using namespace std;
const int N=510;
ll s[N],t[N],n,p[N][N];
int R[N][2],L[N][2],cntr[N][2],cntl[N][2];//R/L表示在当前位上.行列需要满足的要求. 
ull u[N],v[N],c[N][N];
bool vis[N][N];
inline ll read()
{
	ll x=0,ff=1;
	char ch=getchar();
	while(!isdigit(ch)) {if(ch=='-') ff=-1;ch=getchar();}
	while(isdigit(ch)) {x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*ff;
}

inline void init()
{
	get(n);
	rep(i,1,n) get(s[i]);
	rep(i,1,n) get(t[i]);
	rep(i,1,n) cin>>u[i];
	rep(i,1,n) cin>>v[i];
}

inline bool solve(int id)
{
	memset(p,0,sizeof(p));
	memset(vis,0,sizeof(vis));
	memset(cntr,0,sizeof(cntr));
	memset(cntl,0,sizeof(cntl));
	rep(i,1,n) 
	{
		if(R[i][1]==n||R[i][0]==n)
		{
			int k=R[i][1]==n?1:0;
			rep(j,1,n) p[i][j]=k,vis[i][j]=1;
		}
		if(L[i][1]==n||L[i][0]==n)
		{
			int k=L[i][1]==n?1:0;
			rep(j,1,n) p[j][i]=k,vis[j][i]=1;
		}
	}
	rep(i,1,n) rep(j,1,n)
	{
		if(!vis[i][j])
		{
			if((R[i][0]&&L[j][0])||(R[i][1]&&L[j][1]))
			{
				int k;
				if(R[i][0]&&L[j][0]) k=0;
				else k=1;
				p[i][j]=k;
				vis[i][j]=1;
			}
		}
	}
	rep(i,1,n) rep(j,1,n) cntr[i][p[i][j]]++;
	rep(i,1,n) rep(j,1,n) cntl[i][p[j][i]]++;
	rep(i,1,n) rep(j,1,n)
	{
		if(!vis[i][j])
		{
			if(cntr[i][1]>=R[i][1]&&cntl[j][1]>=L[j][1]) continue;
			else if(cntr[i][0]-1>=R[i][0]&&cntl[j][0]-1>=L[j][0])
			{
				p[i][j]=1;
				cntr[i][0]--;cntl[j][0]--;
				cntr[i][1]++;cntl[j][1]++;
			}
		}
	} 
	rep(i,1,n) rep(k,0,1) if(cntr[i][k]<R[i][k]||cntl[i][k]<L[i][k]) return false;
	rep(i,1,n) rep(j,1,n) c[i][j]|=(ull)p[i][j]<<id;
	return true;
}

int main()
{
	//freopen("1.in","r",stdin);
	init();
	rep(i,0,63)
	{
		memset(R,0,sizeof(R));
		memset(L,0,sizeof(L));
		rep(j,1,n) 
		{
			if(!s[j]&&u[j]>>i&1) R[j][1]=n;
			else if(!s[j]&&!(u[j]>>i&1)) R[j][0]=1;
			else if(s[j]&&!(u[j]>>i&1)) R[j][0]=n;
			else R[j][1]=1;
		}
		rep(j,1,n) 
		{
			if(!t[j]&&v[j]>>i&1) L[j][1]=n;
			else if(!t[j]&&!(v[j]>>i&1)) L[j][0]=1;
			else if(t[j]&&!(v[j]>>i&1)) L[j][0]=n;
			else L[j][1]=1;
		}
		if(!solve(i)) {puts("-1");return 0;}
	}
	rep(i,1,n) 
	{
		rep(j,1,n) printf("%llu ",c[i][j]);
		puts("");
	}
	return 0;
} 


