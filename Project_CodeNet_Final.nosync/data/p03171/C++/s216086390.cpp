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
const int N = 3100;

int a[N];
ll dp[N][N][2];

ll calc(int l, int r, int turn) {
    if (dp[l][r][turn] != LINF) {
        return dp[l][r][turn];
    }

    if (l == r) {
        if (turn == 0) {
            return dp[l][r][turn] = a[l];
        } else {
            return dp[l][r][turn] = -a[l];
        }
    }

    if (turn == 0) {
        dp[l][r][turn] = std::max(calc(l + 1, r, turn ^ 1) + a[l], calc(l, r - 1, turn ^ 1) + a[r]);
    } else {
        dp[l][r][turn] = std::min(calc(l + 1, r, turn ^ 1) - a[l], calc(l, r - 1, turn ^ 1) - a[r]);
    }

    return dp[l][r][turn];
}

void run() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dp[i][j][0] = LINF;
            dp[i][j][1] = LINF;
        }
    }

    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    printf("%lld\n", calc(0, n - 1, 0));
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
