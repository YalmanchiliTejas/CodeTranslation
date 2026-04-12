#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const ll mod=1000000007;
    int n;
    cin >> n;
    vector<ll> a(n+1,0);
    ll s=0;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        s=(s+a[i])%mod;
    }
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        s=(s-a[i]+mod)%mod;
        res=(res+a[i]*s)%mod;
    }
    cout << res << "\n";
    return 0;
}
