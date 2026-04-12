#include <bits/stdc++.h>

using namespace std;

#define il inline
#define re register
#define Rep(i, s, e) for (re int i = s; i <= e; ++i)
#define Dep(i, s, e) for (re int i = s; i >= e; --i)
#define file(a) freopen(#a".in", "r", stdin), freopen(#a".out", "w", stdout)

const int N = 3010;

const long long mod = 998244353;

il int read() {
    int x = 0; bool f = true; char c = getchar();
    while (c < '0' || c > '9') {if (c == '-') f = false; c = getchar();}
    while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
    return f ? x : -x;
}

int n, S;
int a[N], f[N];

long long ans;

int main() {
    
    n = read(), S = read();
    Rep(i, 1, n) a[i] = read();

    Rep(i, 1, n) {
        if (a[i] > S) continue;
        if (a[i] == S) ans = (ans + i * (n - i + 1)) % mod;
        else {
            ans = (ans + 1ll * f[S - a[i]] * (n - i + 1)) % mod;
            Dep(j, S, a[i] + 1) f[j] = (f[j] + f[j - a[i]]) % mod;
            f[a[i]] = (f[a[i]] + i) % mod;
        }
    }
    printf("%lld", ans);
    return 0;
}