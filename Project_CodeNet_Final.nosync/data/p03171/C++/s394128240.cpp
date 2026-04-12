#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <tuple>
#include <deque>
#include <numeric>
#include <bitset>
#include <iomanip>
#include <cassert>
#include <chrono>
#include <random>
#include <limits>
#include <iterator>
#include <functional>
#include <sstream>
#include <complex>
using namespace std;

using ll = long long;
using ull = uint64_t;
using P = pair<int, int>;
constexpr double EPS = 1e-9;
constexpr int INF = 1001001001;
constexpr int mod = 1777777777;
// constexpr int mod = 1000000007;
// constexpr int mod = 998244353;

template<class T>
inline bool chmax(T& x, T y){
    if(x < y){
        x = y;
        return true;
    }
    return false;
}
template<class T>
inline bool chmin(T& x, T y){
    if(x > y){
        x = y;
        return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> a(N);
    for(int i = 0; i < N; ++i)  cin >> a[i];

    constexpr ll inf = 1e+15;
    vector<vector<ll>> dp(N + 1, vector<ll>(N + 1, -inf));
    auto MemoRec = [&](auto&& self, int l, int r) -> ll {
        if(dp[l][r] != -inf)    return dp[l][r];
        if(r - l <= 0)  return dp[l][r] = 0;
        
        ll res = -inf;
        chmax(res, a[l] - self(self, l + 1, r));
        chmax(res, a[r - 1] - self(self, l, r - 1));

        return dp[l][r] = res;
    };

    cout << MemoRec(MemoRec, 0, N) << endl;
}