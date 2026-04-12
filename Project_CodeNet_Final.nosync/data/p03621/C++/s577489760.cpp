#include<bits/stdc++.h>
#define mo 998244353
using namespace std;
long long fac[20010],nifac[20010],f[20010];
char s[20010],t[20010];
long long getmi(long long a,long long x)
{
	long long ans=1;
	while (x)
	{
		if (x&1) ans=ans*a%mo;
		a=a*a%mo;
		x>>=1;
	}
	return ans;
}
long long C(int n,int m){return fac[n]*nifac[m]%mo*nifac[n-m]%mo;}
long long A(int n,int m){return fac[n]*nifac[n-m]%mo;}
int main()
{
	scanf("%s\n%s",s+1,t+1);int len=strlen(s+1),same=0,diff=0;
	fac[0]=nifac[0]=1;
	for (int i=1;i<=len;i++)
	{
		same+=((s[i]=='1')&&(t[i]=='1'));
		diff+=((s[i]=='1')&&(t[i]=='0'));
		fac[i]=fac[i-1]*i%mo;
		nifac[i]=getmi(fac[i],mo-2);
	}
	f[0]=1;
	for (int i=1;i<=diff;i++)
	for (int j=1;j<=same;j++) f[j]=(f[j]+i*f[j-1])%mo;
	long long ans=0;
	for (int i=0;i<=same;i++) ans=(ans+f[i]*nifac[diff+i])%mo;
	printf("%lld\n",ans*fac[diff]%mo*fac[diff]%mo*fac[same]%mo*fac[same+diff]%mo);
}
	
	
	
	
	
	
