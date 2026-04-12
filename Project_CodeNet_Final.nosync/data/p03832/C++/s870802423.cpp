#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1010,p=1e9+7;
typedef long long ll;
int inc(int x,int y){x+=y;return x>=p?x-p:x;}
int dec(int x,int y){x-=y;return x<0?x+p:x;}
int mul(int x,int y){return (ll)x*y%p;}
int power(int x,int y){
	int ans=1;
	for (;y;y>>=1,x=mul(x,x))
		if (y&1) ans=mul(ans,x);
	return ans;
}
int n,l,r,L,R,fac[N],ifac[N],dp[N][N];
//dp[i][j]表示用到第i个,和为j的方案数
int main()
{
	scanf("%d%d%d%d%d",&n,&l,&r,&L,&R);
	fac[0]=1;
	for (int i=1;i<=n;i++) fac[i]=mul(fac[i-1],i);
	ifac[n]=power(fac[n],p-2);
	for (int i=n;i;i--) ifac[i-1]=mul(ifac[i],i);
	dp[l-1][0]=fac[n];
	for (int i=l;i<=r;i++)
	for (int cnt=0,k=1;cnt<=R;cnt++,k=mul(k,ifac[i]))
	if (!cnt||cnt>=L)
	for (int j=0;i*cnt+j<=n;j++)
		dp[i][i*cnt+j]=inc(dp[i][i*cnt+j],mul(dp[i-1][j],mul(k,ifac[cnt])));
	printf("%d\n",dp[r][n]);
	return 0;
}