#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int N = 100005;

LL a[N];
int b[N];
LL pre[N];
int main() {
    LL n, m, x;
    cin >> n >> x >> m;
    LL ans = pre[1] = a[1] = x;
    b[x] = 1;
    for (int i = 2; i <= n; i++) {
        a[i] = a[i - 1] * a[i - 1] % m;
        ans = pre[i] = pre[i - 1] + a[i];
        if (b[a[i]] > 0) {
            LL t1 = (n - b[a[i]]) / (i - b[a[i]]), t2 = (n - b[a[i]]) % (i - b[a[i]]);
            ans = pre[b[a[i]] + t2] + (pre[i] - pre[b[a[i]]]) * t1;
            break;
        }
        b[a[i]] = i;
    }
    cout << ans << endl;
    return 0;
}
