#include<bits/stdc++.h>
using namespace std;
template <typename T>
inline void readin(T &x) {
    x = 0;
    T fh = 1;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') fh = -1;
    for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
    x *= fh;
}
inline void d_read(double &x) {
    x = 0.0;
    int fh = 1;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') fh = -1;
    for (; isdigit(ch); ch = getchar()) x = x * 10 + (ch ^ 48);
    if (ch == '.') {
        double num = 1.0;
        ch = getchar();
        for (; isdigit(ch); ch = getchar()) x = x + (num /= 10) * (ch ^ 48);
    }
    x *= fh;
}
template <typename T>
inline void wt(T x) {
    if (x > 9) wt(x / 10);
    putchar(x % 10 + 48);
}
template <typename T>
inline void writeln(T x, char c) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    wt(x);
    putchar(c);
}
const int N = 2e5 + 5;
long long inv, sum, res, x;
const int mod = 1e9 + 7;
inline void qp() {
    inv = 1;
    long long si = 2ll;
    int cnt = mod - 2;
    while(cnt) {
        if (cnt & 1) inv = (inv * si) % mod;
        si = (si * si) % mod;
        cnt >>= 1;
    }
}
int main() {
    int n;
    readin(n);
    for (int i = 1; i <= n; i ++) {
        readin(x);
        res = (res + x * x) % mod;
        sum = (sum + x) % mod;
    }
    qp();
    sum = (sum * sum - res + 1ll * mod) % mod * inv % mod;
    writeln(sum, '\n');
    return 0;
}