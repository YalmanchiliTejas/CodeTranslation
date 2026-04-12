#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
using PL = pair<ll, ll>;
// Welcome to my source code!

vector<ll> divisor(ll n) {
    vector<ll> div;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            div.push_back(i);
            if (i != n / i) div.push_back(n / i);
        }
    }
    return div;
}

int main() {
    int n;
    cin >> n;
    int t[n];
    int maxt = 0;
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        maxt = max(maxt, t[i]);
    }
    vector<ll> div = divisor(maxt);
    sort(div.begin(), div.end());
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (maxt % t[i] != 0) {
            ans += *lower_bound(div.begin(), div.end(), t[i]) - t[i];
        }
    }
    cout << ans << endl;
}
