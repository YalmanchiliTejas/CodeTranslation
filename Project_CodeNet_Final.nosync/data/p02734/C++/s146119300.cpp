#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL mod = 998244353;
const int N = 3005;

int a[N];
int f[N];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        f[0]++;
        for (int k = m; k >= a[i]; k--) {
            f[k] += f[k - a[i]];
            f[k] %= mod;
        }
        ans += f[m];
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}
