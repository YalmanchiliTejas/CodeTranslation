#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using P = pair<int, int>;
int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    const ll k = 1e9 + 7;
    ll sum = 0;
    for(int i = 0; i < n; i++){
        sum += a[i];
    }

    ll sum_2 = 0;
    rep(i,n){
        sum -= (ll)a[i];
        sum_2 += (ll)(sum % k) * (ll)(a[i]%k);
        sum_2 %= k;
    }
    ll ans = sum_2%k;

    cout << ans << endl;
    // cout << k << endl;

return 0;
}