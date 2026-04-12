#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main()
{
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
    int n;
    ll a[200005],sum;
    ll mod=1e9+7;

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    ll ans = 0;
    for(int i = 1; i <= n; i++)
    {
        ans = (ans+a[i]*sum)%mod;
        sum = sum+ a[i];
        sum = sum%mod;
    }
    cout << ans;
}
