#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#define N 20004
#define D 202
using namespace std;
typedef long long ll;
const ll Mod = 1e9 + 7;

int n, d;
ll f[N][D];
char s[N];

ll DP(int len, int now, int op) {
    if (len == 0) return !now;
    if (!op && f[len][now] != -1) return f[len][now];
    int num = s[n - len + 1] - '0';
    ll res = 0;
    for (int i = 0; i <= (op ? num : 9); ++i)
        (res += DP(len - 1, (now - i + d) % d, op & (i == num))) %= Mod;
    if (!op) f[len][now] = res;
    return res;
}

int main() {
#ifdef whyqx
    freopen("work.in", "r", stdin);
    freopen("work.out", "w", stdout);
#endif
    memset(f, -1, sizeof f);
    scanf("%s", s + 1);
    n = strlen(s + 1);
    cin >> d;
    cout << ((DP(n, 0, 1) - 1) % Mod + Mod) % Mod;
    return 0;
}
