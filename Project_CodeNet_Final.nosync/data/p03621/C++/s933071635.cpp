#include<iostream>
#include<cstdio>
#include<cstring>
#define N 10010
#define ll long long
#define mod 998244353
using namespace std;
ll ksm(ll a,ll b=mod-2)
{
	if(b==0) return 1;
	if(b==1) return a;
	ll q=ksm(a,b>>1);
	if(b&1)return q*q%mod*a%mod;
	return q*q%mod;
}
ll fac[N],inv[N];
int f[N][N];
ll C(int a,int b)
{
	if(b<0 || b>a) return 0;
	if(a==b || b==0) return 1;
	return fac[a]*inv[b]%mod*inv[a-b]%mod;
}
char s1[N],s2[N];
int main()
{
	int n,m;
	scanf("%s%s",s1,s2);
	n=strlen(s1);
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	inv[n]=ksm(fac[n],mod-2);
	for(int i=n-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
	int sum1=0,sum2=0;
	for(int i=0;i<n;i++)
	sum1+=s1[i]=='1' && s2[i]=='1';
	for(int i=0;i<n;i++)
	sum2+=s1[i]=='1' && s2[i]=='0';
	for(int i=0;i<=sum2;i++) f[0][i]=fac[i]*fac[i]%mod;
	for(int i=1;i<=sum1;i++)
        for(int j=1;j<=sum2;j++)
            f[i][j]=(1ll*f[i-1][j]*i%mod*j%mod+1ll*f[i][j-1]*j%mod*j%mod)%mod;
    ll ans=0;
    for(int i=0;i<=sum1;i++)
    ans=(ans+1ll*f[sum1-i][sum2]*fac[i]%mod*fac[i]%mod*C(sum1,i)%mod*C(sum1+sum2,i))%mod;
	printf("%lld\n",ans);
	return 0;
}
