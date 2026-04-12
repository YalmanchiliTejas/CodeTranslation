#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

#define iter(i, n) for (int i = 1; i <= n; ++i)
#define iter0(i, n) for (int i = 0; i < n; ++i)
#define forw(i, a, b) for (int i = a; i <= b; ++i)

#define NR 101000

const int mod = 998244353;
const int g = 3;

//k! * F_k() * cycle
int n, c0, c1, ta[NR], tb[NR], fac[NR], inv[NR];
char sa[NR], sb[NR];

int pr(int a, int z) {
    int s = 1;
    while (z > 0) {
        if (z % 2 == 1) s = 1ll * s * a % mod;
        a = 1ll * a * a % mod;
        z /= 2;
    }
    return s;
}

void fft(int *a, int n, int ty) {
    for (int i = n >> 1, j = 1, k; j < n - 1; ++j) {
        if (i > j) swap(a[i], a[j]);
        for (k = n >> 1; k <= i; k >>= 1) i ^= k;
        i ^= k;
    }

    for (int m = 2; m <= n; m <<= 1) {
        int h = m >> 1, wm = pr(g, (mod - 1) / m * (ty == +1 ? 1 : (m - 1)));

        for (int i = 0; i < n; i += m) {
            int w = 1;
            for (int j = i; j < i + h; ++j) {
                int u = a[j], v = 1ll * w * a[j + h] % mod;
                a[j] = (u + v) % mod;
                a[j + h] = (u - v + mod) % mod;
                w = 1ll * w * wm % mod;
            }
        }
    }

    if (ty == -1) {
        int iv = pr(n, mod - 2);
        iter0(i, n) a[i] = 1ll * a[i] * iv % mod;
    }
}

typedef vector<int> Poly;

Poly operator+(const Poly &a, const Poly &b) {
    int la = a.size(), lb = b.size();
    
    Poly c(max(la, lb));

    iter0(i, la) c[i] = a[i];
    iter0(i, lb) c[i] = (c[i] + b[i]) % mod;
    return c;
}

Poly operator*(const Poly &a, const Poly &b) {
    int la = a.size(), lb = b.size(), N;
    if (la == 0 || lb == 0) return Poly();

    for (N = 1; N < (la + lb); N <<= 1);
    iter0(i, N) ta[i] = tb[i] = 0;
    iter0(i, la) ta[i] = a[i];
    iter0(i, lb) tb[i] = b[i];
    
    
    fft(ta, N, +1), fft(tb, N, +1);
    iter0(i, N) ta[i] = 1ll * ta[i] * tb[i] % mod;
    fft(ta, N, -1);
   // printf("!!%d %d %d\n", la, lb, N);
   // iter0(i, la) printf("%d ", a[i]); puts("");
   // iter0(i, lb) printf("%d ", b[i]); puts("");
   // iter0(i, N) printf("%d ", ta[i]); puts("");
    Poly c(la + lb - 1);
    iter0(i, la + lb - 1) c[i] = ta[i];
    while ((c.back() == 0 || c.size() > c0 + c1 + 1) && !c.empty()) c.pop_back();
    return c;
}

Poly pow(Poly a, int z) {
    Poly s; s.push_back(1);
    while (z > 0) {
        if (z % 2 == 1) s = s * a;
        a = a * a;
        z /= 2;
    }
    return s;
}

int main() {
    //freopen("19E.in", "r", stdin);
    scanf("%s%s", sa + 1, sb + 1);
    n = strlen(sa + 1); 
    iter(i, n) {
        if (sa[i] == '1' && sb[i] == '1') ++c1;
        else if (sa[i] == '1' && sb[i] == '0') ++c0;
    }

    fac[0] = inv[0] = 1;
    iter(i, c0 + c1) {
        fac[i] = 1ll * fac[i - 1] * i % mod;
        inv[i] = pr(fac[i], mod - 2);
    }

   // printf("%d %d\n", c0, c1);

    Poly a(c1 + 2), b(c1 + 1);
    
    iter(i, c1 + 1) a[i] = 1ll * inv[i];// * inv[i - 1] % mod;
    //forw(i, 0, c1) b[i] = 1;
    //printf("cc%lld\n", 1ll * fac[c0] * fac[c1] % mod);
    Poly tmp = pow(a, c0);
    tmp.resize(c0 + c1 + 1);
    int ans = 0;
    //printf("!%d %d\n", tmp.size(), c0 + c1);
    forw(i, c0, c0 + c1) {
//        tmp[i] = 1ll * tmp[i] * fac[i - c0] % mod * fac[i] % mod;
        //printf("%d ", tmp[i]);
        ans = (ans + 1ll * tmp[i] * fac[c0 + c1] % mod * fac[c1] % mod * fac[c0]) % mod;
    }
    //printf("%lld\n", 1ll * (tmp * b)[c0 + c1] * fac[c0 + c1] % mod * fac[c0] % mod);
    printf("%d\n", ans);
    return 0;
}