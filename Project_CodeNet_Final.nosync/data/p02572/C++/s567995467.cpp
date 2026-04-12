#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mxn=2e5+3,du=1e9+7;
int n;
int a[mxn];
int sum[mxn];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=n;i>=1;i--)
    {
        sum[i]=sum[i+1]+a[i];
        sum[i]%=du;
    }
    int ans=0;
    for (int i=1;i<=n;i++)
    {
        ans+=(a[i]*sum[i+1])%du;
        ans%=du;
    }
    cout<<ans;
	return 0;
}
