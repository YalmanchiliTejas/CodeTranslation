#include <cstdio>
#include <iostream>
#include <cassert>
#include <string>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <unordered_map>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
const LL MOD = (LL)1e9 + 7;
const int MAXN = 234567;
LL fac[MAXN], ifac[MAXN];

LL qpow(LL n, LL p) {
   LL B = n;
   LL ans = 1;
   while (p) {
       if (p % 2) ans = (ans * B) % MOD;
       B = (B * B) % MOD;
       p >>= 1;
   }
   return ans;
}

LL C(LL a, LL b) {
   if (b >= a || !b) return 1;
   return ((fac[a] * ifac[b]) % MOD) * ifac[a - b] % MOD;
}

int main() {
    fac[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fac[i] = (fac[i - 1] * i) % MOD;
    }
    ifac[MAXN - 1] = qpow(fac[MAXN - 1], MOD - 2);
    for (int i = MAXN - 2; i >= 0; i--) {
        ifac[i] = (ifac[i + 1] * (i + 1)) % MOD;
    }
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    LL ans = 0;
    for (int i = 1; i < N; i++) {
        int kind = (N - i);
        LL sum = (M * M) % MOD;
        sum = (sum * kind) % MOD;
        sum = (sum * i) % MOD;
        ans = (ans + sum) % MOD;
    }
    for (int i = 1; i < M; i++) {
        int kind = (M - i);
        LL sum = (N * N) % MOD;
        sum = (sum * kind) % MOD;
        sum = (sum * i) % MOD;
        ans = (ans + sum) % MOD;
    }
    ans = (ans * C(N * M - 2, K - 2)) % MOD;
    printf("%lld\n", ans);
    return 0;
}
