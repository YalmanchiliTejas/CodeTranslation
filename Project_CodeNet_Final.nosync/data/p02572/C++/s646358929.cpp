#include <iostream>
using namespace std;
const int INF=0x3f3f3f3f,maxn=2e5+10,mod=1e9+7;
long long a[maxn],n,m,sum[maxn];
int main()
{
	long long i,j,k,ans=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
		//sum[i]%=mod;
	}
	for(i=1;i<=n;i++)
	{
		long long plus=0;
		plus=sum[n]-sum[i];
	//	cout<<plus<<endl;
		plus%=mod;
		ans+=(plus*a[i])%mod;
		ans%=mod;
	}
	cout<<ans<<endl;
	return 0;
}
