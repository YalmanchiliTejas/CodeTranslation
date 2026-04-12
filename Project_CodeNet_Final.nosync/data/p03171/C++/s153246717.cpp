#include<cstdio>
#define int long long 
#define max(a,b)((a)>(b)?(a):(b))
const int N=3003;
int f[N][N],n,a[N];
signed main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",a+i),f[i][0]=a[i];
	for(int k=1;k<n;k++)
	  for(int i=1;i+k<=n;i++)
		f[i][k]=max(a[i]-f[i+1][k-1],a[i+k]-f[i][k-1]);
	printf("%lld",f[1][n-1]);
	return 0;
}