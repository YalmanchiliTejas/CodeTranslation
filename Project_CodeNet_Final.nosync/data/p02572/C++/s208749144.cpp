#include <bits/stdc++.h>

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define setIO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
#define trav(e, x) for (auto &(e) : (x))
#define pb(x) push_back(x)
#define eb(x...) emplace_back(x)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int) (x).size()
#define lc(i) 2*i
#define rc(i) 2*i+1
#define int long long
using namespace std;
using ii = pair<int, int>;
using vi = vector<int>;

const int N = 1e5 + 5, MOD = 1e9 + 7, INF = 1e9 + 5;

int add(int x, int y) {
    return ((x % MOD) + (y % MOD)) % MOD;
}

int mul(int x, int y) {
    return ((x % MOD) * (y % MOD)) % MOD;
}

signed main() {
    FAST_IO;
//    setIO("input.txt", "output.txt");

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    int dp[n];
    dp[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) dp[i] = add(dp[i + 1], a[i]);
    int ans = 0;
    for (int i = 0; i < n - 1; i++) ans = add(ans, mul(a[i], dp[i + 1]));
    cout << ans % MOD;
}
