//
//  main.cpp
//

#include <algorithm>
#include <array>
#include <assert.h>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <math.h>
#include <memory>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using ll = int64_t;
using ull = uint64_t;
constexpr ll LL_MAX = numeric_limits<ll>::max();
constexpr ull ULL_MAX = numeric_limits<ull>::max();

template<typename T>
vector<T> make_vec_nd(T init, ll size) {
	return vector<T>(size, init);
}
template<typename T, typename... Args>
auto make_vec_nd(T init, ll size, Args... rest) {
	auto inner = make_vec_nd(init, rest...);
	return vector<decltype(inner)>(size, inner);
}

#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define rrep(i, a, b) for (ll i = (a)-1; i >= (b); i--)

int main() {
    string digits_str;
    cin >> digits_str;
    ll N = digits_str.size();
    vector<ll> digits(N);
    rep(i,0,N) {
        digits[i] = digits_str[i] - '0';
    }
    ll K;
    cin >> K;
    vector<ll> nonzero_cnt(N+1);
    rep(n,1,N+1) {
        nonzero_cnt[n] = nonzero_cnt[n-1] + ((digits[n-1] > 0) ? 1 : 0);
    }
    auto dp = make_vec_nd((ll)0, N+1, K+1);
    rep(n,1,N+1) {
        rep(k,0,K+1) {
            dp[n][k] = 0;
            if (digits[n-1] > 0) {
                if (nonzero_cnt[n-1] == k) {
                    dp[n][k] += 1;
                } else if (nonzero_cnt[n-1] == k-1) {
                    dp[n][k] += digits[n-1] - 1;
                }
            }
            dp[n][k] += dp[n-1][k];
            if (k >= 1) {
                dp[n][k] += 9 * dp[n-1][k-1];
            }
        }
    }
    ll ans = dp[N][K];
    if (nonzero_cnt[N] == K) {
        ans++;
    }
    cout << ans << endl;
}
