#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MOD=1e9+7;
int n;
ll a[200005],tot,ans;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		tot+=a[i];
	}
	for(int i=0;i<n;i++)
	{
		tot-=a[i];
		ans=(ans+a[i]*(tot%MOD))%MOD;
		//cout<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}