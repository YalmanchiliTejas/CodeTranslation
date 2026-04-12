#include<bits/stdc++.h>
using namespace std;

typedef long long s64;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
const int N=10000+5,D=998244353;
s64 mi(s64 x,int y=D-2)
{
	s64 ans=1;
	while(y)
	{
		if(y&1)ans=ans*x%D;
		x=x*x%D;y>>=1; 
	} 
	return ans;
}
char s1[N],s2[N];
const int n=1<<15;
s64 jie[N],niv_jie[N],dp[n],g[n];

int rev[n];s64 w[n];
void ntt(s64 a[],int flag)
{
	rep(i,1,n-1)rev[i]=rev[i/2]/2+i%2*n/2;
	rep(i,0,n-1)
	if(i<rev[i])swap(a[i],a[rev[i]]);
	for(int i=1;i<n;i*=2)
	{
		int nn=i*2;
		s64 wn=mi(3,(D-1)/nn*flag+D-1);
		w[0]=1;
		rep(k,1,i-1)w[k]=w[k-1]*wn%D;
		for(int j=0;j<n;j+=nn)
		{
			s64 *a1=a+j,*a2=a1+i;
			rep(k,0,i-1)
			{
				s64 x=a1[k],y=a2[k]*w[k]%D;
				a1[k]=(x+y)%D;
				a2[k]=(x-y)%D;
			}
		}
	}
	if(flag==-1)
	{
		s64 niv_n=mi(n);
		rep(i,0,n-1)a[i]=a[i]*niv_n%D; 
	}
}
s64 DP(int a,int b)
{
	rep(i,0,a){dp[i]=1;g[i]=niv_jie[i+1];}
	while(b)
	{
	//	cerr<<b<<endl;
		ntt(g,1);
		if(b&1)
		{
			ntt(dp,1);
			rep(i,0,n-1)dp[i]=dp[i]*g[i]%D;
			ntt(dp,-1);
		//	cerr<<b<<endl;
			rep(i,a+1,n-1)dp[i]=0;
		}
		rep(i,0,n-1)g[i]=g[i]*g[i]%D;
		ntt(g,-1);
		rep(i,a+1,n-1)g[i]=0;
		b>>=1;
	}
	return dp[a];
}

int main()
{
	//freopen("1.in","r",stdin);
	scanf("%s%s",s1+1,s2+1);
	int n=strlen(s1+1);
	jie[0]=1;
	rep(i,1,n)jie[i]=jie[i-1]*i%D;
	niv_jie[n]=mi(jie[n]);
	per(i,n,1)niv_jie[i-1]=niv_jie[i]*i%D;
	int a=0,b=0;
	rep(i,1,n)
	if(s1[i]=='1')
		if(s2[i]=='1')++a;
		else ++b;
	cout<<(jie[b]*jie[a]%D*jie[a+b]%D*DP(a,b)%D+D)%D;
}