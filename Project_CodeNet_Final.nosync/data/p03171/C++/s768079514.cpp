#include <math.h>
#include <ctype.h>
#include <limits.h>
#include <assert.h>

#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>
#include <functional>

#define nl                std::cout << "\n"
#define in(x)             std::cin  >> (x)
#define out(x)            std::cout << (x) << " "
#define err(x)            std::cerr << #x << "=" << (x) << " | "

#define inn(x)            int x; in(x)
#define rep(i, n)         for (int i =  0 ; i < (n); ++i)
#define per(i, n)         for (int i = (n) - 1; i > -1; --i)
#define repr(i, l, r)     for (int i = (l); i < (r); ++i)

#define no                puts("NO")
#define yes               puts("YES")

using ll  = long long int;
using vi  = std::vector<int>;
using ii  = std::pair<int, int>;
using iii = std::pair< ii, int>;
using vii = std::vector<ii>;

const int N = 1010101;
const int MD = 1e9 + 7;

void solve() {
    inn(n);
    int a[n]; rep(i, n) in(a[i]);

    ll dp[n + 1][n + 1]; // dp[i][l] ans to a[i: i + l]
    bool turn = n&1; // Taro's turn if l&1 == turn

    rep(i, n + 1) dp[i][0] = 0;
    repr(l, 1, n + 1) {
        bool taro = (turn == (l&1));
        rep(i, n - l + 1) {
            if (taro)
            dp[i][l] = std::max(
                        a[i] + dp[i + 1][l - 1],
                        a[i + l - 1] + dp[i][l - 1]
                       );
            else
            dp[i][l] = std::min(
                        -a[i] + dp[i + 1][l - 1],
                        -a[i + l - 1] + dp[i][l - 1]
                       );
        }
    }
    out(dp[0][n]);
}

int main() {
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

    //inn(t); repr(tc, 1, t + 1)
    solve();

    return 0;
}
