#include <bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr ll INF = 1e17;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector< vector<ll> > dpL(2, vector<ll>(n + 1, -INF));
    dpL[false][0] = 0;
    for (int i = 0; i + 1 < n; i += 2) {
        dpL[false][i + 2] = max(dpL[false][i + 2], dpL[false][i] + a[i]);
        dpL[true][i + 2] = max(dpL[true][i + 2], max(dpL[false][i], dpL[true][i]) + a[i + 1]);
    }

    if (n % 2 == 0) {
        cout << max(dpL[false][n], dpL[true][n]) << "\n";
        return 0;
    }

    vector< vector<ll> > dpR(2, vector<ll>(n + 1, -INF));
    dpR[false][n - 1] = 0;
    for (int i = n - 1; i >= 2; --i) {
        dpR[false][i - 2] = max(dpR[false][i - 2], dpR[false][i] + a[i]);
        dpR[true][i - 2] = max(dpR[true][i - 2], max(dpR[false][i], dpR[true][i]) + a[i - 1]);        
    }

    ll ans = -INF;
    for (int i = 0; i < n; i += 2) {
        ans = max(ans, max(dpL[false][i], dpL[true][i]) + max(dpR[false][i], dpR[true][i]));
    }
    cout << ans << "\n";
    return 0;
}
