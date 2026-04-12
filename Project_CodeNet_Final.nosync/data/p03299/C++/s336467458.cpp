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
inline void myassert(bool a,string s){ if(!a)cerr<<s<<endl,exit(0);}
inline int read()
{
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch) && ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
	return ~f?s:-s;
}

const int maxn=120;
const int mod=1e9+7;

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

int n,h[maxn];
int sx[maxn],tx;

inline void init()
{
	n=read();
	REP(i,1,n)h[i]=read(),sx[i]=h[i]; tx=n;
	sort(sx+1,sx+tx+1); tx=unique(sx+1,sx+tx+1)-sx-1;
}

int g[maxn][2];

inline void doing()
{
	DREP(i,tx,1)
	{
		int f[2]={0},empty=1;
		int mult=power(2,sx[i]-sx[i-1]-1);
		REP(j,1,n)if(h[j]>=sx[i])
		{
			if(h[j]>sx[i])while(j<n && h[j+1]>sx[i])++j;
			else g[j][0]=0,g[j][1]=1;
			if(empty)f[0]=g[j][0],f[1]=g[j][1]*2%mod;
			else {
				int tmp[2]; ;
				tmp[0]=((ll)f[0]*g[j][0]+(ll)f[1]*g[j][0]+(ll)f[0]*g[j][1]*2+(ll)f[1]*g[j][1])%mod;
				tmp[1]=((ll)f[1]*g[j][1])%mod;
				f[0]=tmp[0]; f[1]=tmp[1];
			}
			empty=0;
			if(j==n || h[j+1]<sx[i])
			{
				g[j][0]=f[0],g[j][1]=(ll)f[1]*mult%mod;
			}
		}else f[0]=f[1]=0,empty=1;
	}
	int ans=(g[n][0]+g[n][1])%mod;
	printf("%d\n",ans);
}

int main()
{
	init();
	doing();
	return 0;
}
