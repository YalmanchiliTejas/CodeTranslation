#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;
int n;
ll a[MAXN], pos[MAXN], ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = n; i >= 1; i--) pos[i] = (pos[i + 1] + a[i]) % MOD;
    for (int i = 1; i <= n - 1; i++) ans += a[i] * pos[i + 1] % MOD, ans %= MOD;
    cout << ans;
    return 0;
}
