#include"iostream"
#include"cstdio"
#include"cmath"
#include"cstring"
#include"algorithm"
#include"stack"
#include"queue"
using namespace std;

#define read(x) scanf("%d",&x)
#define readl(x) scanf("%lld",&x)
#define ll long long 
#define ull unsigned long long
#define MOD 1000000007

int n;
ll a[200005];
ll sum[200005];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=n;i>=1;i--)
	{
		sum[i]=(sum[i+1]+a[i])%MOD;	
	}
	for(int i=1;i<n;i++)
	{
		sum[0]=(sum[0]+a[i]*sum[i+1])%MOD;
	}
	printf("%lld\n",sum[0]%MOD);
	return 0;
} 