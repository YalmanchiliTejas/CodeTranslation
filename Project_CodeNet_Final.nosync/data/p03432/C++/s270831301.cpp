#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int N=8005;
typedef long long ll;
const ll mod=998244353;

int power_mod(int a,int b)
{
	int ans=1;
	while (b) 
	{
		if (b&1) ans=(ll)ans*a%mod;
		a=(ll)a*a%mod;
		b>>=1;
	}
	return ans;
}
inline void MOD(int &x) {if (x>=mod) x-=mod;}


int n,m;

int dp[N*4],t[N*4],tmp[N*4];

int om[N*4],on[N*4],rev[N*4],len;
void init(int n)
{
	int l=0;
	len=1;
	while (len<n) len<<=1,l++;
	
	int g=power_mod(3,(mod-1)/len),inv=power_mod(g,mod-2);
	for (int i=0;i<len;i++) 
	{
		om[i]= i==0 ?1:(ll)om[i-1]*g%mod;
		on[i]= i==0 ?1:(ll)on[i-1]*inv%mod;
		rev[i]=(rev[i>>1]>>1)|((i&1)<<l-1);
	}
}
void ntt(int *a,int *om,int n)
{
	for (int i=0;i<n;i++) if (rev[i]>i) swap(a[i],a[rev[i]]);
	for (int len=2;len<=n;len<<=1) 
		for (int m=len/2,x,i=0;i<n;i+=len) 
			for (int j=0;j<m;j++) 
			{
				x=(ll)om[n/len*j]*a[i+j+m]%mod;
				MOD(a[i+j+m]=a[i+j]-x+mod);
				MOD(a[i+j]+=x);
			}
}
void dft(int *a) {ntt(a,om,len);}
void idft(int *a) 
{
	ntt(a,on,len);
	int inv=power_mod(len,mod-2);
	for (int i=0;i<len;i++) a[i]=(ll)a[i]*inv%mod;
}
int jc[N],ny[N];

int C(int n,int m) 
{
	return (ll)jc[n]*ny[m]%mod*ny[n-m]%mod;
}
int main()
{
	scanf("%d%d",&n,&m);
	init(n*2+1);
	
	jc[0]=jc[1]=ny[0]=ny[1]=1;
	for (int i=2;i<=n+2;i++) jc[i]=(ll)jc[i-1]*i%mod,ny[i]=(mod-mod/i)*ny[mod%i]%mod;
	for (int i=2;i<=n+2;i++) ny[i]=(ll)ny[i-1]*ny[i]%mod;
	

	for (int i=0;i<=n;i++) dp[i]=1;
	//dft(dp);idft(dp);
	//for (int i=0;i<=n;i++) printf("%d ",dp[i]);
	
	for (int i=2;i<=m;i++) 
	{
		for (int j=0;j<=n;j++) tmp[j]=(ll)dp[j]*ny[j]%mod,t[j]=ny[j+2];t[0]=0;
		for (int j=n+1;j<len;j++) tmp[j]=t[j]=0;
		
		dft(tmp),dft(t);
		for (int j=0;j<len;j++) tmp[j]=(ll)tmp[j]*t[j]%mod;
		idft(tmp);
		
		for (int j=0;j<=n;j++) 
			dp[j]=((ll)dp[j]*(j*(j+1)/2+1)+(ll)tmp[j]*jc[j+2])%mod;
			//,printf("dp[%d][%d]=%d\n",i,j,dp[j]);
	}
	int ans=0;
	for (int i=0;i<=n;i++) ans=((ll)dp[i]*C(n,i)+ans)%mod;
	printf("%d\n",ans);
	return 0;
}
