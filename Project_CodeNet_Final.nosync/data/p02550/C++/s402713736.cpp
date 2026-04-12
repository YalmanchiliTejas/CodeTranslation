#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

const int MAXN = 2E5 + 5;

LL n, x, m;
LL sum[MAXN], a[MAXN], last[MAXN], st, ed;

int main() {
    // freopen("1.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> x >> m;
    a[1] = x, sum[1] = a[1];
    for (int i = 2; i <= n; i++) {
        a[i] = a[i - 1] * a[i - 1] % m;
        sum[i] = sum[i - 1] + a[i];
        if (a[i] == 0) {
            cout << sum[i - 1];
            return 0;
        }
        if (last[a[i]]) {
            st = last[a[i]];
            ed = i - 1;
            break;
        }
        last[a[i]] = i;
    }
    if (!ed)
        cout << sum[n];
    else {
        LL len = ed - st + 1;
        LL cyclesum = sum[ed] - sum[st - 1];
        LL ans = sum[st - 1];
        LL tot = n - st + 1;
        ans += tot / len * cyclesum;
        int rem = tot % len;
        ans += sum[st + rem - 1] - sum[st - 1];
        cout << ans;
    }
    return 0;
}
