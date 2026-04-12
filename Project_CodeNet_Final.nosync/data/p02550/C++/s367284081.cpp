#include <bits/stdc++.h>
#define int long long

using namespace std;

constexpr int MAXN = 1e5 + 5, MOD = 1e9 + 7;

int n, ans, ans2, x, m, arr[MAXN], sum[MAXN], vis[MAXN], sz;

signed main() {
    std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> x >> m;
    ans += x;
    int i;
    for (i = 1; i < n; i++) {
        x = x * x % m;
        ans2 += x;
        if (x == 0) return cout << ans2 + ans, 0;
        if (!vis[x]) {
            arr[i] = x;
            vis[x] = i;
        } else {
            i--;
            sz = i - vis[x] + 1;
            break;
        }
    }
    if (!sz) return cout << ans2 + ans << endl, 0;
    int cnt = (n - vis[x]) / sz, res = (n - vis[x]) % sz;
    for (int j = 1; j <= i; j++)
        sum[j] = sum[j - 1] + arr[j];
    ans += sum[vis[x] - 1];
    ans += (sum[i] - sum[vis[x] - 1]) * cnt;
    ans += (sum[vis[x] - 1 + res] - sum[vis[x] - 1]);
    cout << ans << endl;
    return 0;
}
//492443256176507
//491945869537148
