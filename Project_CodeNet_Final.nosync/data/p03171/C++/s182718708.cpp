#include <bits/stdc++.h>
#define ALL(obj) begin(obj), end(obj)
using namespace std;

using ll = long long;
using ull = unsigned long long;
const ll INF = 1e18;

int N;
vector<vector<ll>> dp;
vector<ll> a;

ll rec(int l = 0, int r = N) {
    if (r == l) return 0;
    ll &ret = dp[l][r];
    if (ret != INF) return ret;

    if ((N - (r - l)) % 2 == 0) {  // 先手
        ret = max(a[l] + rec(l + 1, r), rec(l, r - 1) + a[r - 1]);
    } else {  // 後手
        ret = min(-a[l] + rec(l + 1, r), rec(l, r - 1) - a[r - 1]);
    }

    return ret;
}

int main() {
    cin >> N;
    a.assign(N, 0);
    dp.assign(N + 5, vector<ll>(N + 5, INF));
    for (int i = 0; i < N; i++) {
        cin >> a.at(i);
    }

    cout << rec() << endl;

    return 0;
}
