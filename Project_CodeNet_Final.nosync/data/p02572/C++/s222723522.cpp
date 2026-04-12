#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define MOD 1000000007

int main() {
    ll n;
    cin >> n;

    vector<ll> a(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum = (sum + a[i]) % MOD;
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        sum = (sum - a[i] + MOD) % MOD;
        ans = (ans + a[i] * sum) % MOD;
    }

    cout << ans << endl;
}