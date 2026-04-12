#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 10000
#define MO 998244353
using namespace std;
int dp[MAXN+5][MAXN+5];
char A[MAXN+5],B[MAXN+5];
int fact[MAXN+5],inv[MAXN+5];
int PowMod(int a,int b)
{
	int ret=1;
	while(b)
	{
		if(b&1)
			ret=1LL*ret*a%MO;
		a=1LL*a*a%MO;
		b>>=1;
	}
	return ret;
}
void prepare()
{
	fact[0]=1;
	for(int i=1;i<=MAXN;i++)
		fact[i]=1LL*fact[i-1]*i%MO;
	inv[MAXN]=PowMod(fact[MAXN],MO-2);
	for(int i=MAXN-1;i>=0;i--)
		inv[i]=1LL*inv[i+1]*(1LL*i+1LL)%MO;
}
int C(int n,int m)
{
	return 1LL*fact[n]*inv[m]%MO*inv[n-m]%MO;
}
int main()
{
	prepare();
	scanf("%s %s",A+1,B+1);
	int n=strlen(A+1),x=0,y=0;
	for(int i=1;i<=n;i++)
		if(A[i]=='1'&&B[i]=='1')
			x++;
		else if(A[i]=='1'&&B[i]=='0')
			y++;
	for(int j=0;j<=y;j++)
		dp[0][j]=1LL*fact[j]*fact[j]%MO;
	for(int i=1;i<=x;i++)
		for(int j=1;j<=y;j++)
			dp[i][j]=(1LL*dp[i-1][j]*i%MO*j%MO+1LL*dp[i][j-1]*j%MO*j%MO)%MO;
	int ans=0;
	for(int i=0;i<=x;i++)
		ans=(1LL*ans+1LL*dp[x-i][y]*fact[i]%MO*fact[i]%MO*C(x,i)%MO*C(x+y,i)%MO)%MO;
	printf("%d\n",ans);
	return 0;
}