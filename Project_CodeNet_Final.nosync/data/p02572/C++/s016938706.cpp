#include <bits/stdc++.h>
#define int long long

using namespace std;

constexpr int MAXN = 2e5 + 5, MOD = 1e9 + 7;

template<typename T>
inline void read(T& x, T f = 1, char ch = getchar()) {
    x = 0;
    while (!isdigit(ch)) f = (ch == '-') ? -1 : 1, ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar();
    x *= f;
}

int tc, n, m, ans;
array<int, MAXN> a, pre;
string s, t;

signed main() {
    std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++)
        (pre[i] = pre[i - 1] + a[i]) %= MOD;
    for (int i = 1; i <= n; i++)
        ans = (ans + a[i] * (pre[n] - pre[i] + MOD) % MOD) % MOD;
    cout << (ans + MOD) % MOD << endl;
    return 0;
}