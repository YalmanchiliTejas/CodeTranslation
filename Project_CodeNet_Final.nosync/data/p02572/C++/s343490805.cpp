#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
//cout << setprecision(20) << 

int main() {
    ll n; cin >> n;
    vector<ll> v(n);
    vector<ll> a(n + 1);
    a[0] = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        a[i + 1] = a[i] + v[i];
    }

    ll sum = 0;
    for (int i = 0; i < n - 1; ++i) {
        ll tmp = a[n] - a[i + 1];
        tmp %= MOD;
        sum += tmp * v[i];
        sum %= MOD;
    }
    cout << sum << endl;
}