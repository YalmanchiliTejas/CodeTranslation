#include <bits/stdc++.h>
using namespace std;

const int maxn = (int)(1e5) + 5;
int a[maxn];

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    int M = (n + 1) >> 1;
    long long ret = a[M] - a[M + 1];
    if (n & 1) ret = max(a[M] + a[M - 1], 3 * a[M] - a[M + 1]);
    for (int i = 1; i <= M; ++i) ret -= a[i] * 2;
    for (int i = M + 1; i <= n; ++i) ret += a[i] * 2;
    cout << ret << endl;
    return 0;
}
