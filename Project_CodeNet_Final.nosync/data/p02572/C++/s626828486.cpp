#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f
using namespace std;
#define mod 1000000000+7
ll a[200005],sum[200005];
int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    ll ans=0;
    for(int i=1; i<=n; i++)
    {
        ans+=(a[i]%1000000007)*((sum[n]-sum[i])%1000000007);
        ans%=1000000007;
    }
    cout<<ans<<endl;
    return 0;
}
