#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (int)((x).size())
#define xx first
#define yy second

const int N = 1e4 + 1;
const int D = 1e2 + 1;
const int mod = 1e9 + 7;

int add(int x, int y, int m) {
    return ((x + y) % m + m) % m;
}
int mul(int x, int y, int m) {
    return (x * y) % mod;
}

string k, S = "0123456789";
int x, memo[2][D][N];

int dp(int match, int rem, int i) {
    if (i == sz(k))
        return !rem ? 1 : 0;
    if (memo[match][rem][i] != -1)
        return memo[match][rem][i];
    int ans = 0;
    for (int d = 0; d <= (match ? (k[i] - '0') : 9); d++) {
        int nmatch = match & (d == (k[i] - '0'));
        int nrem = add(rem, d, x);
        ans = add(ans, dp(nmatch, nrem, i + 1), mod);
    }
    return memo[match][rem][i] = ans;
}

void solve() {
    cin >> k >> x;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < x; j++)
            fill(memo[i][j], memo[i][j] + N, -1);
    int ans = dp(1, 0, 0);
    ans = add(ans, -1, mod);
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int _; cin >> _; while (_--)
    solve();
    return 0;
}
