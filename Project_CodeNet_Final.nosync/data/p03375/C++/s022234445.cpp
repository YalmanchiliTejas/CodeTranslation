#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#define LL long long
using namespace std;
LL C[3010][3010],S[3010][3010];
LL n,p;
void pre()
{
	for(LL i=0;i<=3001;i++)
	{
		C[i][0]=1;
		for(LL j=1;j<=i;j++) C[i][j]=(C[i-1][j]+C[i-1][j-1])%p;
	}
	S[0][0]=1;
	for(LL i=1;i<=3001;i++)
	{
		S[i][1]=1;
		for(LL j=2;j<=i;j++) S[i][j]=(S[i-1][j]*j%p+S[i-1][j-1])%p;
	}
}
LL pow(LL a,LL b,LL mod)
{
	LL ans=1;
	while(b)
	{
		if(b&1) ans=ans*a%mod;
		a=a*a%mod;b>>=1;
	}
	return ans;
}
int main()
{
	LL ans=0;scanf("%lld %lld",&n,&p);
	pre();
	for(LL i=0;i<=n;i++)
	{
		LL s=C[n][i]*pow(2,pow(2,n-i,p-1),p)%p;
		LL tot=0;
		for(LL j=0;j<=i;j++) tot=(tot+pow(2,(n-i)*j%(p-1),p)*S[i+1][j+1]%p)%p;
		ans=(ans+(i&1?-1:1)*s%p*tot%p)%p;
	}
	printf("%lld",(ans+p)%p);
}