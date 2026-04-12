#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

const int maxn = 110000;
const ll Mod = 998244353;

ll pw(ll x,ll k)
{
	ll re=1ll;
	for(;k;k>>=1,x=x*x%Mod)
		if(k&1) re=re*x%Mod;
	return re;
}
ll si[maxn],sN[maxn],Ni[maxn];
void pre()
{
	si[0]=1ll;for(ll i=1;i<maxn;i++) si[i]=si[i-1]*i%Mod;
	sN[maxn-1]=pw(si[maxn-1],Mod-2);
	for(ll i=maxn-2;i>=0;i--) sN[i]=sN[i+1]*(i+1)%Mod;
	for(ll i=1;i<maxn;i++) Ni[i]=sN[i]*si[i-1]%Mod;
}
ll C(const int i,const int j){return si[i]*sN[j]%Mod*sN[i-j]%Mod;}

int N,ln;
ll g[maxn]; int id[maxn];
void DFT(ll s[],int sig,int nown)
{
	for(int i=0;i<nown;i++) if(i<id[i]) swap(s[i],s[id[i]]);
	int kk=N/nown;
	for(int m=2;m<=nown;m<<=1)
	{
		int t=m>>1,tt=nown/m;
		for(int j=0;j<nown;j+=m)
		{
			for(int i=0;i<t;i++)
			{
				ll wn=sig==1?g[i*tt*kk]:g[(nown-i*tt)*kk];
				ll tx=s[j+i],ty=s[j+i+t]*wn%Mod;
				s[j+i]=(tx+ty)%Mod;
				s[j+i+t]=(tx-ty+Mod)%Mod;
			}
		}
	}
	if(sig==-1) for(int i=0;i<nown;i++) (s[i]*=Ni[nown])%=Mod;
}

ll f[maxn];
int n,m,e;
void FFT(ll s[])
{
	//for(int i=0;i<N;i++) printf("%lld ",s[i]); puts("");
	DFT(s,1,N);
	for(int i=0;i<N;i++) s[i]=s[i]*s[i]%Mod;
	DFT(s,-1,N);
	//for(int i=0;i<N;i++) printf("%lld ",s[i]); puts("");
	for(int i=m+1;i<N;i++) s[i]=0;
}
ll temp[maxn];
void get_f(ll f[],int k)
{
	temp[0]=si[m];
	for(;k;k>>=1,FFT(f)) if(k&1)
	{
		DFT(temp,1,N); DFT(f,1,N);
		for(int i=0;i<N;i++) temp[i]=temp[i]*f[i]%Mod;
		DFT(temp,-1,N); DFT(f,-1,N);
		for(int i=m+1;i<N;i++) temp[i]=0;
	}
	for(int i=0;i<N;i++) f[i]=temp[i];
}
void solve()
{
	for(int i=0;i<N;i++) id[i]=(id[i>>1]>>1)|((i&1)<<ln-1);
	get_f(f,e);
}
char s1[maxn],s2[maxn];

int main()
{
	pre();
	scanf("%s%s",s1,s2); n=strlen(s1);
	for(int i=0;i<n;i++)
	{
		if(s1[i]-'0'+s2[i]-'0'==1) e++;
		else if(s1[i]-'0'+s2[i]-'0'==2) m++;
	}e>>=1;
	N=1,ln=0;
	while(N<=2*m) N<<=1,ln++;
	g[0]=1ll; g[1]=pw(3ll,(Mod-1)/N);
	for(int i=2;i<=N;i++) g[i]=g[i-1]*g[1]%Mod;
	
	for(int i=0;i<=m;i++) f[i]=sN[i+1];
	solve();
	ll ans=0;
	for(int i=0;i<=m;i++) 
		(ans+=f[i]*si[e]%Mod*sN[m-i]%Mod*si[e+i]%Mod*si[m-i]%Mod*si[m-i]%Mod*C(e+m,m-i)%Mod)%=Mod;
	printf("%lld\n",ans);
	
	return 0;
}
