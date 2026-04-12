#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m=1e9+7;
int main()
{
    int n;
    cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    ll ans=0;ll sum=arr[n-1];
    for(int i=n-2;i>=0;i--)
    {
        ans=(ans + (sum*arr[i]))%m;
        sum=(sum + arr[i])%m;
    }
    cout<<ans;
}
