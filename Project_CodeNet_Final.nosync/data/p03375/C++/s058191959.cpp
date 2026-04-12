#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=3005;
int n,P,ans,f[N],C[N][N],S[N][N];
ll pw(ll a,ll b,ll m){ll r=1;for(;b;b>>=1,a=a*a%m)if(b&1)r=r*a%m;return r;}
int main()
{
	scanf("%d%d",&n,&P);S[1][1]=1;
	for(int i=2;i<N;i++)for(int j=1;j<=i;j++)S[i][j]=(S[i-1][j-1]+1ll*j*S[i-1][j])%P;
	for(int i=C[0][0]=1;i<=n;i++)for(int j=C[i][0]=1;j<=i;j++)C[i][j]=(C[i-1][j-1]+C[i-1][j])%P;
	for(int i=0;i<=n;i++)
	{
		ll b=pw(2,n-i,P),c=1,s=0;
		for(int j=0;j<=i;j++,c=1ll*c*b%P)s=(s+1ll*S[i+1][j+1]*c)%P;
		s=1ll*s*C[n][i]%P*pw(2,pw(2,n-i,P-1),P)%P;
		if(i&1)ans=(ans+P-s)%P;else ans=(ans+s)%P;
	}
	printf("%d\n",ans);
	return 0;
}
