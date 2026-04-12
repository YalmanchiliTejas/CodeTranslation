#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define xx first
#define yy second

const int N = 3001;
const ll oo = 1e16;

int n, a[N];
ll memo[N][N];

ll dp(int i, int j) {
    if (i == j)
        return a[i];
    if (memo[i][j] != -oo)
        return memo[i][j];
    ll ans = -oo;
    ans = max(ans, a[i] - dp(i + 1, j));
    ans = max(ans, a[j] - dp(i, j - 1));
    return memo[i][j] = ans;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        fill(memo[i], memo[i] + n, -oo);
    cout << dp(0, n - 1) << '\n';
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int _; cin >> _; while (_--)
    solve();
    return 0;
}
