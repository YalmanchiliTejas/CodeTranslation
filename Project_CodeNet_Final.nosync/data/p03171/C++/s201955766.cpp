#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define endl "\n"

const ll INF = 1e15;
const int MOD = 1e9 + 7;
const double EPS = 1e-7;
const double PI = acos(-1.0);

const int N = 3e3 + 5;;

ll n, a[N], dp[N][N][2];

ll solve(int l, int r, int p) {
    if (l > r) return 0;
    ll& ret = dp[l][r][p];
    if (~ret) return ret;
    if (p) ret = min(solve(l + 1, r, 1 - p) - a[l], solve(l, r - 1, 1 - p) - a[r]);
    else   ret = max(solve(l + 1, r, 1 - p) + a[l], solve(l, r - 1, 1 - p) + a[r]);
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> n;

    for (int i = 0; i < n; ++i) 
        cin >> a[i];

    memset(dp, -1, sizeof(dp));
    cout << solve(0, n - 1, 0) << endl;
}
