#include<cstdio>
using namespace std;
typedef long long ll;
const int N=3005;
int ans,n,mod,jc[N],inv[N],s[N][N],f[N],pw[N*N];
int ksm(int x,int y,int mod)
{
  int res=1;
  while (y) {if (y&1) res=(ll)res*x%mod;x=(ll)x*x%mod;y>>=1;}
  return res;
}
int c(int n,int m) {return (ll)jc[n]*inv[m]%mod*inv[n-m]%mod;}
int main()
{
	scanf("%d%d",&n,&mod);
	jc[0]=jc[1]=inv[0]=inv[1]=pw[0]=1;
	for (int i=2;i<=n;i++) jc[i]=(ll)jc[i-1]*i%mod,inv[i]=(ll)(mod-mod/i)*inv[mod%i]%mod;
	for (int i=2;i<=n;i++) inv[i]=(ll)inv[i-1]*inv[i]%mod;
	for (int i=1;i<=n*n;i++) pw[i]=(ll)pw[i-1]*2%mod;
	for (int i=0;i<=n;i++) s[i][0]=1;//初始化，都有一种可能分到0个集合 
	for (int i=1;i<=n;i++)
	  for (int j=1;j<=i;j++)
	    s[i][j]=((ll)s[i-1][j-1]+(ll)(j+1)*s[i-1][j]%mod)%mod;//<=i个元素分入j个非空集合的方案数  
	for (int i=0;i<=n;i++)
	{
	   for (int j=0;j<=i;j++) f[i]=((ll)f[i]+(ll)s[i][j]*pw[(n-i)*j]%mod)%mod;
	   f[i]=(ll)f[i]*ksm(2,ksm(2,n-i,mod-1),mod)%mod;	
	}
	for (int i=0;i<=n;i++)
	  if (i&1) ans=((ll)ans-(ll)c(n,i)*f[i]%mod+mod)%mod;
	  else ans=((ll)ans+(ll)c(n,i)*f[i]%mod)%mod;
	printf("%d\n",ans);
	return 0;
}