//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<ctime>
#include<cctype>
#include<queue>
#include<deque>
#include<stack>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<string>
#include<ctime>
#include<cmath>
#include<cctype>
#include<cstdlib>
#include<queue>
#include<deque>
#include<stack>
#include<vector>
#include<algorithm>
#include<utility>
#include<bitset>
#include<set>
#include<map>
#define ll long long
#define db double
#define INF 10000000000000000ll
#define inf 1000000000
#define ldb long double
#define pb push_back
#define put_(x) printf("%d ",x);
#define get(x) x=read()
#define gt(x) scanf("%d",&x)
#define gi(x) scanf("%lf",&x)
#define put(x) printf("%d\n",x)
#define putl(x) printf("%lld\n",x)
#define rep(p,n,i) for(RE int i=p;i<=n;++i)
#define go(x) for(int i=lin[x],tn=ver[i];i;tn=ver[i=nex[i]])
#define fep(n,p,i) for(RE int i=n;i>=p;--i)
#define vep(p,n,i) for(RE int i=p;i<n;++i)
#define pii pair<int,int>
#define mk make_pair
#define RE register
#define P 1000000007ll
#define gf(x) scanf("%lf",&x)
#define pf(x) ((x)*(x))
#define uint unsigned long long
#define ui unsigned
#define EPS 1e-4
#define sq sqrt
#define S second
#define F first
using namespace std;
char *fs,*ft,buf[1<<15];
inline char gc()
{
	return (fs==ft&&(ft=(fs=buf)+fread(buf,1,1<<15,stdin),fs==ft))?0:*fs++;
}
inline int read()
{
	RE int x=0,f=1;RE char ch=gc();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=gc();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=gc();}
	return x*f;

}
const int MAXN=3010;
int n,mod;
int fac[MAXN],inv[MAXN];
int s[MAXN][MAXN];
inline int ksm(int b,int p,int M)
{
	int cnt=1;
	while(p)
	{
		if(p&1)cnt=(ll)cnt*b%M;
		b=(ll)b*b%M;p=p>>1;
	}
	return cnt;
}
inline int C(int a,int b){return (ll)fac[a]*inv[b]%mod*inv[a-b]%mod;}
int main()
{
	//freopen("1.in","r",stdin);
	get(n);get(mod);
	fac[0]=1;
	rep(1,n,i)fac[i]=fac[i-1]*(ll)i%mod;
	inv[n]=ksm(fac[n],mod-2,mod);
	fep(n-1,0,i)inv[i]=(ll)inv[i+1]*(i+1)%mod;
	s[0][0]=1;
	rep(1,n+1,i)rep(1,i,j)s[i][j]=(s[i-1][j-1]+(ll)s[i-1][j]*j)%mod;
	int op=-1,ans=0;
	rep(0,n,i)
	{
		op=-op;
		int cnt=ksm(2,n-i,mod-1);
		cnt=ksm(2,cnt,mod)*(ll)C(n,i)%mod;
		int sum=0;
		int c1=ksm(2,n-i,mod),c2=1;
		rep(0,i,k)
		{
			sum=(sum+(ll)c2*s[i+1][k+1])%mod;
			c2=(ll)c1*c2%mod;
		}
		ans=(ans+op*(ll)cnt*sum)%mod;
	}
	put((ans+mod)%mod);
	return 0;
}
