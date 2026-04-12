#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
	int arr[200000];
	int pre[200001]={0};
int main()
{
	int n;
	cin >> n;

	int i;
	for(i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	for(i=n-1;i >=0; i--)
	{
		pre[i] = (pre[i+1] + arr[i])%mod;
	}
	long long ans = 0;
	for(i=0;i<n-1;i++)
	{
		ans += (1LL*arr[i]*pre[i+1])%mod;
		ans = ans%mod;
	}
	cout<<ans<<endl;
}
