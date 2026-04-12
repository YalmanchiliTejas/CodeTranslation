//
//  main.cpp
//

#include <algorithm>
#include <array>
#include <assert.h>
#include <iomanip>
#include <iostream>
#include <limits>
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

template<typename T>
vector<T> make_vec_nd(T init, size_t size) {
    return vector<T>(size, init);
}
template<typename T, typename... Args>
auto make_vec_nd(T init, size_t size, Args... rest) {
    auto inner = make_vec_nd(init, rest...);
    return vector<decltype(inner)>(size, inner);
}

int main() {
    ll N;
    cin >> N;
    vector<ll> ais;
    ll sum = 0;
    for (ll i = 0; i < N; i++) {
        ll ai;
        cin >> ai;
        ais.push_back(ai);
        sum += ai;
    }
    auto dp = make_vec_nd((ll)0, ais.size()+1, ais.size()+1);
    for (ll i = N-1; i >= 0; i--) {
        for (ll j = i+1; j <= N; j++) {
            dp[i][j] = max(-dp[i+1][j] + ais[i], -dp[i][j-1] + ais[j-1]);
        }
    }
    cout << dp[0][N] << endl;
}

