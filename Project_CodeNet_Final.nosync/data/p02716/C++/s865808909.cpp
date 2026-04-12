//
//  main.cpp
//

#include <algorithm>
#include <array>
#include <assert.h>
#include <complex>
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

ll N;
vector<ll> As;
unordered_map<ll, unordered_map<ll, ll>> memo;

ll solve(ll i, ll n) {
    if (memo[i].find(n) != memo[i].end()) {
        return memo[i][n];
    }
    if (n == 0) {
        return 0;
    }
    ll left = N - i;
    if (left % 2 == 0 && n > left / 2) {
        return numeric_limits<ll>::min();
    }
    if (left % 2 == 1 && n > left / 2 + 1) {
        return numeric_limits<ll>::min();
    }
    ll ret = max(solve(i+1, n), As[i]+solve(i+2, n-1));
    memo[i][n] = ret;
    return ret;
}

int main() {
    cin >> N;
    As.resize(N);
    rep(i,0,N) {
        cin >> As[i];
    }
    cout << solve(0, N/2) << endl;
}
