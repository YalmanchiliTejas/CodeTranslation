/*
 　　　　　／＞　 フ
 　　　　　| 　_　 _|
 　 　　　／`ミ _x 彡
 　　 　 /　　　 　 |
 　　　 /　  ヽ　　 ?
 　／￣|　　 |　|　|
 　| (￣ヽ＿_ヽ_)_)
 　＼二つ
  */

#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MP make_pair
#define ll long long
#define fi first
#define se second
using namespace std;

template <typename T>
void read(T &x) {
    x = 0; bool f = 0;
    char c = getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
    for (;isdigit(c);c=getchar()) x=x*10+(c^48);
    if (f) x=-x;
}

template<typename F>
inline void write(F x, char ed = '\n') {
    static short st[30];short tp=0;
    if(x<0) putchar('-'),x=-x;
    do st[++tp]=x%10,x/=10; while(x);
    while(tp) putchar('0'|st[tp--]);
    putchar(ed);
}

template <typename T>
inline void Mx(T &x, T y) { x < y && (x = y); }

template <typename T>
inline void Mn(T &x, T y) { x > y && (x = y); }

const int P = 1e9 + 7;
const int N = 400005;
char s[N];
int sum[N], f[N], a[N], m, n;
ll inv[N], fac[N], ans;
template <typename T>
inline void Add(T &x, T y) { x += y, x >= P && (x -= P, 0); }

inline ll C(int n, int m) {
    if (n < m || n < 0) return 0;
    return fac[n] * inv[m] % P * inv[n-m] % P;
}

namespace subtask {
    int main(int lim) {
        if (n & 1) return write(0), 0;
        int pre = 1;
        for (int i = 1;i <= m; i++) if (!a[i]) {
            if ((i - pre) & 1) Mn(lim, i - pre);
            pre = i + 1;
        }
        n >>= 1, lim = (lim + 1) >> 1;
        f[0] = sum[0] = 1;
        for (int i = 1;i <= n; i++) {
            f[i] = sum[i-1] - (i >= lim + 1 ? sum[i - lim - 1] : 0), Add(f[i], P);
            sum[i] = sum[i-1], Add(sum[i], f[i]);
        }
        for (int i = 1;i <= lim; i++)
            Add(ans, 1ll * f[n-i] * i * 2 % P);
        write(ans);
        return 0;
    }
}

int main() {
    read(n), read(m), scanf ("%s", s + 1);
    for (int i = 1;i <= m; i++) a[i] = s[i] == s[1];
    for (int i = 1;i <= m; i++)
        if (!a[i]) return subtask::main((i - 1) | 1);
    if (n == 1) return write(0), 0;
    inv[0] = inv[1] = fac[0] = fac[1] = 1;
    for (int i = 2;i <= n + 2; i++) 
        inv[i] = (P - P / i) * inv[P % i] % P;
    for (int i = 2;i <= n + 2; i++)
        inv[i] = inv[i-1] * inv[i] % P, fac[i] = fac[i-1] * i % P;
    for (int i = 0;i + i <= n; i++) 
        ans += C(n - i, i) + C(n - 2 - i, i);
    write(ans % P);
    return 0;
}
