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

const int maxn=2e5+20;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;

int n,m;
char str[maxn];
int lim;
int f[maxn];

inline void CHECK1()
{
	REP(i,1,m)if(str[i]=='B')return;
	f[0]=1;f[1]=1;
	REP(i,2,n)f[i]=(f[i-1]+f[i-2])%mod;
	printf("%d\n",(f[n-2]+f[n])%mod);
	exit(0);
}

inline void init()
{
	n=read();m=read();
	scanf("%s",str+1);
	if(str[1]=='B')
	{
		REP(i,1,m)str[i]=str[i]=='B'?'R':'B';
	}
	CHECK1();
	lim=inf;
	int lstb=0;
	REP(i,1,m)
	{
		if(str[i]=='B')
		{
			int num=i-lstb-1;
			if(lstb==0)chkmin(lim,num+(num+1&1));
			else if(num&1)chkmin(lim,num);
			lstb=i;
		}
	}
	lim=lim+1>>1;
}

inline void doing()
{
	if(n&1)puts("0"),exit(0);
	n>>=1;
	f[0]=1;int s=1;
	REP(i,1,n)
	{
		f[i]=s;
		s=(s+f[i])%mod;
		if(i-lim>=0)s=(s-f[i-lim]+mod)%mod;
	}
	//int ans=f[n>>1];
	int ans=0;
	REP(i,1,lim)ans=(ans+(ll)i*f[n-i])%mod;
	ans=(ll)ans*2%mod;
	printf("%d\n",ans);
}

int main()
{
	init();
	doing();
	return 0;
}
