// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
// #pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

#ifdef PERVEEVM_LOCAL
    #define debug(x) std::cerr << (#x) << ":\t" << (x) << std::endl
#else
    #define debug(x) 238;
#endif

#define fastIO std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0)
#define NAME "File"

using ll = long long;
using ld = long double;

#ifdef PERVEEVM_LOCAL
    std::mt19937 rnd(238);
#else
    std::mt19937 rnd(std::chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

const double PI = atan2(0.0, -1.0);
const int INF = 0x3f3f3f3f;
const ll LINF = (ll)2e18;
const int N = 10100;
const int MOD = (int)1e9 + 7;

int add(int a, int b, int mod = MOD) {
    if (a + b >= mod) {
        return a + b - mod;
    }
    return a + b;
}

int sub(int a, int b, int mod = MOD) {
    if (a - b < 0) {
        return a - b + mod;
    }
    return a - b;
}

int mul(int a, int b, int mod = MOD) {
    return (int)(1ll * a * b % mod);
}

int binpow(int a, int n, int mod = MOD) {
    if (n == 0) {
        return 1;
    }
    if (n % 2 == 0) {
        return binpow(mul(a, a, mod), n / 2, mod);
    } else {
        return mul(binpow(a, n - 1, mod), a, mod);
    }
}

int rev(int a, int mod = MOD) {
    return binpow(a, mod - 2, mod);
}

char s[N];
int dp[N][110][2];

// 0 - all equal
// 1 - has less

void run() {
    int n;
    scanf("%s\n%d", s, &n);

    dp[0][0][0] = 1;
    int l = strlen(s);
    for (int i = 1; i <= l; ++i) {
        for (int dig = 0; dig <= 9; ++dig) {
            for (int from = 0; from < n; ++from) {
                int to = (from + dig) % n;

                dp[i][to][1] = add(dp[i][to][1], dp[i - 1][from][1]);

                if (dig < s[i - 1] - '0') {
                    dp[i][to][1] = add(dp[i][to][1], dp[i - 1][from][0]);
                }
                if (dig == s[i - 1] - '0') {
                    dp[i][to][0] = add(dp[i][to][0], dp[i - 1][from][0]);
                }
            }
        }
        // for (int dig = 0; dig <= s[i - 1] - '0'; ++dig) {
        //     for (int from = 0; from < n; ++from) {
        //         int to = from + dig;
        //         if (to >= n) {
        //             to -= n;
        //         }

        //         dp[i][to] = add(dp[i][to], dp[i - 1][from]);
        //     }
        // }
    }

    printf("%d\n", sub(add(dp[l][0][0], dp[l][0][1]), 1));
}

int main(void) {
    // freopen(NAME".in", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    auto start = std::chrono::high_resolution_clock::now();
    run();
    auto end = std::chrono::high_resolution_clock::now();

    #ifdef PERVEEVM_LOCAL
        std::cerr << "Execution time: "
                  << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
                  << " ms" << std::endl;
    #endif

    return 0;
}
