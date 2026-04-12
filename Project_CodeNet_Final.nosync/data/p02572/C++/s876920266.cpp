#include<bits/stdc++.h>
using namespace std;

const int mod=1000000007;
int n,a[200005],sum[200005];
typedef long long ll;
ll ans;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=n;i>=1;i--)
		sum[i]=sum[i+1]+a[i],sum[i]%=mod;
	for(int i=1;i<n;i++)
	{
		ll tot=sum[i+1];
		ans+=tot*ll(a[i]);
		ans%=mod;
	}
	printf("%d\n",int(ans));
	return 0;
}