#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

template <class T>
inline void read(T &x) {
    x = 0;
    int f = 0;
    char ch = getchar();
    while (!isdigit(ch))    { f |= ch == '-'; ch = getchar(); }
    while (isdigit(ch))     { x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar(); }
    x = f ? -x : x;
    return;
}

typedef long long LL;

LL a[200010], f[200010], sum[200010];
LL n;

int main() {
    read(n);
    for (int i = 1; i <= n; ++i)    read(a[i]);
    sum[1] = a[1];
    for (int i = 2; i <= n; ++i)    sum[i] = sum[i - 2] + a[i];
    for (int i = 2; i <= n; ++i) {
        if (i & 1) {
            f[i] = std::max(f[i - 1], f[i - 2] + a[i]);
        } else {
            f[i] = std::max(f[i - 2] + a[i], sum[i - 1]);
        }
    }
    printf("%lld\n", f[n]);
    return 0;
}