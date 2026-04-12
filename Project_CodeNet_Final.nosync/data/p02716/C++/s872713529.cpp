#include <bits/stdc++.h>

using namespace std;
long long f[200005][3][2];
bool memo[200005][3][2];
int a[200005];
int n;
long long calc(int i, int j, int last) {
    if (j <= -2) return -1e18;
    if (i > n) return (i / 2 + j == n / 2 ? 0: -1e18);
    long long &res = f[i][j + 1][last];
    if (memo[i][j + 1][last])
        return res;
    memo[i][j + 1][last] = 1;
    res = calc(i + 1, (i / 2 + j) - (i + 1) / 2, 0);
    if (last) return res;
    res = max(res, calc(i + 1, (i / 2 + j + 1) - (i + 1) / 2, 1) + a[i]);
    return res;
}
int main() {
#ifdef LDT
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    //f[i][j] = max when choose (i / 2 + j) element
    cout << calc(1, 0, 0);
    return 0;
}