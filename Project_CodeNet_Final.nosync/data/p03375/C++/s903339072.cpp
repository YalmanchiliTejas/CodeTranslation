#include<bits/stdc++.h>
#define maxn 3005
using namespace std;
int n,mod,c[maxn][maxn],g[maxn][maxn];
int Pow(int a,int b,const int mod = ::mod){
	int s=1;for(;b;b>>=1,a=1ll*a*a%mod) b&1&&(s=1ll*s*a%mod); return s;
}
int main()
{
	scanf("%d%d",&n,&mod);
	for(int i=0;i<=n;i++)
		for(int j=c[i][0]=g[i][0]=1;j<=i;j++)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod,g[i][j]=(g[i-1][j-1]+1ll*(j+1)*g[i-1][j])%mod;
	int ans=0;
	for(int i=0;i<=n;i++){
		int s=0,x=Pow(2,n-i);
		for(int j=0,pw=1;j<=i;j++,pw=1ll*pw*x%mod) s=(s+1ll*g[i][j]*pw)%mod;
		ans=(ans+1ll*(i&1?-1:1)*c[n][i]*s%mod*Pow(2,Pow(2,n-i,mod-1)))%mod;
	}
	printf("%d\n",(ans+mod)%mod);
}