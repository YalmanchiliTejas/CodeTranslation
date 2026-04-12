#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; i >= a; i--)
#define int ll
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

// auto mod int
const int mod = 1000000007;

signed main() {
    int n;
    cin >> n;
    int a[n];
    rep(i, 0, n) cin >> a[i];
    int s[n + 1];
    s[0] = 0;
    rep(i, 0, n) s[i + 1] = (s[i] + a[i]) % mod;
    int ans = 0;
    rep(i, 0, n) ans = (ans + a[i] * (s[n] - s[i + 1] + mod) % mod) % mod;
    cout << ans << "\n";
}