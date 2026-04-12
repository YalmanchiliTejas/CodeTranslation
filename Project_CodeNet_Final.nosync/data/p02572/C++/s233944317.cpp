#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int mod = 1e9 + 7;
int pre[N], a[N];
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = (pre[i - 1] + a[i]) % mod;
    }
    int ans = 0;
    for (int i = 2; i <= n; i++) {
        ans = (1LL * pre[i - 1] * a[i] + 1LL * ans) % mod;
    }
    cout << ans % mod << "\n";
    return 0;
}