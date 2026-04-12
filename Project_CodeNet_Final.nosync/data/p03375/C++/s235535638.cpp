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

const int maxn=3e3+20;

int n,mod;

inline int power(int a,int b,const int mod)
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
int S[maxn][maxn];

inline void prepare()
{
	jc[0]=jc[1]=jcn[0]=jcn[1]=inv[1]=1;
	REP(i,2,n)jc[i]=(ll)jc[i-1]*i%mod,inv[i]=(ll)(mod-mod/i)*inv[mod%i]%mod,jcn[i]=(ll)jcn[i-1]*inv[i]%mod;
	S[0][0]=1;
	REP(i,1,n+1)REP(j,1,i)S[i][j]=(S[i-1][j-1]+(ll)S[i-1][j]*j)%mod;
}

inline void init()
{
	n=read();mod=read();
}

inline int C(int n,int m){ return (ll)jc[n]*jcn[m]%mod*jcn[n-m]%mod;}


inline void doing()
{
	int ans=0;
	REP(i,0,n)
	{
		int xs=(ll)C(n,i)*(i&1?-1:1),res=0;
		int num0=power(2,n-i,mod),num1=power(2,n-i,mod-1);
		int t=power(2,num1,mod),t1=1;
		REP(j,0,i)
		{
			res=(res+(ll)S[i+1][j+1]*t%mod*t1)%mod;
			t1=(ll)t1*num0%mod;
		}
		ans=(ans+(ll)xs*res)%mod;
	}
	ans=(ans+mod)%mod;
	printf("%d\n",ans);
}

int main()
{
	init();
	prepare();
	doing();
	return 0;
}
