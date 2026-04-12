#include <bits/stdc++.h>

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define FILE_IO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#define trav(e, x) for (auto &e : x)
#define pb(x) push_back(x)
#define eb(x...) emplace_back(x)
#define all(x) x.begin(), x.end()
#define sz(x) (int) (x).size()
#define int long long
using namespace std;
typedef pair<int, int> ii;

const int N = 3001;
int a[N];
int dp[N][N][2];

int f(int i, int j, int k) {
    if (i > j) return 0;
    if (dp[i][j][k] > -1) return dp[i][j][k];
    int ans;
    if (k == 1) ans = max(f(i + 1, j, 0) + a[i], f(i, j - 1, 0) + a[j]);
    else ans = min(f(i + 1, j, 1), f(i, j - 1, 1));
    return dp[i][j][k] = ans;
}

signed main() {
    FAST_IO;
    //FILE_IO;

    int n;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++) dp[i][j][0] = dp[i][j][1] = -1;
    int x = f(0, n - 1, 1);
    int y = sum - x;
    cout << x - y;
}
