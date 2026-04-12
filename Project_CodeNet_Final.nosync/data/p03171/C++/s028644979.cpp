// #pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;
using vii = vector<int>;
using pii = pair<int, int>;

const ll INF = numeric_limits<ll>::max(),
         MOD = 1e9 + 7;

const int INF_i = numeric_limits<int>::max(),
          MAX = 3e3;

int n;
vll v, s;
ll dp[MAX][MAX];

ll f(int i, int j) {
    if (i == j) return v[i];
    ll &res = dp[i][j];
    if (res != -1) return res;
    res = v[i] + s[j + 1] - s[i + 1] - f(i + 1, j);
    res = max(res, v[j] + s[j] - s[i] - f(i, j - 1));
    return res;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    // freopen("in.in", "r", stdin);
    memset(dp, -1, sizeof dp);
    cin >> n;
    v.resize(n);
    s.resize(n + 1);
    for (ll &e : v) cin >> e;
    partial_sum(v.begin(), v.end(), s.begin() + 1);
    s[0] = 0;
    cout << 2 * f(0, n - 1) - s.back() << '\n';
}