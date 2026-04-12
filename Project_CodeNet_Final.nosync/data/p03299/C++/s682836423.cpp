#include <cstdio>
#include <cstring>
#include <algorithm>
#define P 1000000007

using namespace std;

typedef long long ll;

ll h[111], Mn[111][111], Sm[111][111], SS[111][111], n, F[111];

ll powmod(ll x, ll y = P - 2, ll p = P) {
    ll ans = 1;
    while(y) {
        if(y & 1) ans = ans * x % p;
        x = x * x % p;
        y >>= 1;
    }
    return ans;
}

int main() {
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++) scanf("%lld", &h[i]);
    h[0] = (h[n + 1] = 1);
    for(int i = 1; i <= n; i++) {
        Mn[i][i] = h[i], Sm[i][i] = h[i], SS[i][i] = h[i];
        for(int j = i + 1; j <= n; j++) Mn[i][j] = min(Mn[i][j - 1], h[j]), Sm[i][j] = Sm[i][j - 1] + h[j], SS[i][j] = SS[i][j - 1] + max(h[j] - h[j - 1], 0ll);
    }
    F[0] = 1;
    for(int i = 1; i <= n; i++) {
        F[i] = F[i - 1] * 2 % P;
        for(int j = 1; j <= i; j++) {
            int r = Mn[j][i], l = max(h[i + 1], h[j - 1]) + 1;
            if(l <= r) F[i] = (F[i] + 2 * F[j - 1] * (powmod(2, SS[j][i] - l + 1) - powmod(2, SS[j][i] - r))) % P;
        }
    }
    printf("%lld\n", (F[n] % P + P) % P);
    return 0;
}
