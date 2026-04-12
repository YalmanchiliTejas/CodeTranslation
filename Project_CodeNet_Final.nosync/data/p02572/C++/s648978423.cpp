#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll mod=1e9+7;
int main()
{
    ll n ;
    cin >> n ;
    ll sum=0 , ans=0;
    int arr[n];
    for(int i = 0 ; i < n ; i++)
    {
        cin >> arr[i];
        sum+=arr[i];
    }
    for(int i = 0 ; i < n ; i++)
    {
        sum-=arr[i];
        ans+=((arr[i]%mod)*(sum%mod));
        ans%=mod;
    }
    cout << ans;
    return 0;
}
