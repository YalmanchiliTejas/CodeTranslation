#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

#define int long long

using namespace std;

typedef long long ll;

ll C[3010][3010], G[3010][3010], K1[3010], K2[3010], F[3010], n, P;

ll phi(ll x) {
    ll ans = 1;
    for(int i = 2; i * i <= x; i++) if(x % i == 0) {
        ans *= i - 1;
        x /= i;
        while(x % i == 0) x /= i, ans *= i;
    }
    if(x != 1) ans *= x - 1;
    return ans;
}

ll powmod(ll x, ll y, ll p) {
    ll ans = 1;
    while(y) {
        if(y & 1) ans = ans * x % p;
        x = x * x % p;
        y >>= 1;
    }
    return ans;
}

#undef int
int main() {
#define int long long
    scanf("%lld%lld", &n, &P);
    for(int i = 0; i <= n; i++) K2[i] = !i ? 2 : K2[i - 1] * K2[i - 1] % P, K1[i] = !i ? 1 : K1[i - 1] * 2 % P;
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= i; j++) {
            C[i][j] = !j ? 1 : (C[i - 1][j - 1] + C[i - 1][j]) % P;
            G[i][j] = !j ? 1 : (G[i - 1][j - 1] + G[i - 1][j] * (j + 1)) % P;
        }
    ll ans = 0, ph = phi(P);
    for(int i = 0; i <= n; i++)
        for(int j = 0, s = 1; j <= i; j++, s = s * K1[n - i] % P)
            ans = (ans + (i & 1 ? -1 : 1) * C[n][i] * G[i][j] % P * s % P * K2[n - i]) % P;
    printf("%lld\n", (ans % P + P) % P);
    return 0;
}