#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define pa pair<int,int>
const int Maxn=3010;
const int inf=2147483647;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*f;
}
int n,mod;
int fac[Maxn],fin[Maxn],inv[Maxn],s[Maxn][Maxn];
void pre()
{
	fac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=(LL)fac[i-1]*i%mod;
	inv[0]=inv[1]=1;
	for(int i=2;i<=n;i++)inv[i]=(LL)(mod-mod/i)*inv[mod%i]%mod;
	fin[0]=1;
	for(int i=1;i<=n;i++)fin[i]=(LL)fin[i-1]*inv[i]%mod;
	s[0][0]=1;
	for(int i=1;i<=n+1;i++)
	{
		s[i][0]=0;
		for(int j=1;j<=i;j++)
		s[i][j]=(LL)(s[i-1][j-1]+(LL)j*s[i-1][j]%mod)%mod;
	}
}
int C(int n,int m)
{
	if(n<m)return 0;
	return (LL)fac[n]*fin[m]%mod*fin[n-m]%mod;
}
int Pow(int x,int y,int mod)
{
	if(!y)return 1;
	if(y==1)return x;
	int t=Pow(x,y>>1,mod),re=(LL)t*t%mod;
	if(y&1)re=(LL)re*x%mod;
	return re;
}
int main()
{
	n=read(),mod=read();
	pre();
	int ans=0;
	for(int i=0;i<=n;i++)//i位不合法 
	{
		int t=0,tmp=Pow(2,n-i,mod);
		for(int j=0;j<=i;j++)//1分到j个数 
		t=(LL)(t+(LL)Pow(tmp,j,mod)*s[i+1][j+1]%mod)%mod;
		t=(LL)t*Pow(2,Pow(2,n-i,mod-1),mod)%mod*C(n,i)%mod;
//		printf("%d\n",t);
		if(i&1)ans=(ans-t+mod)%mod;
		else ans=(ans+t)%mod;
	}
	printf("%d",ans);
}