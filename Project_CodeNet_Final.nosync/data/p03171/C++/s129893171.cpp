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
#include <cstring>
using namespace std;

using ll = long long;
using P = pair<int, int>;
constexpr int INF = 1001001001;
constexpr int mod = 1000000007;
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
    vector<ll> a(N);
    for(int i = 0; i < N; ++i)  cin >> a[i];
    vector<vector<ll>> dp(N + 1, vector<ll>(N + 1, -1));
    auto MemoRec = [&](auto&& self, int left, int right) -> ll {
        if(dp[left][right] != -1)   return dp[left][right];
        if(left == right)   return dp[left][right] = 0;
        ll res = a[left] - self(self, left + 1, right);
        chmax(res, a[right - 1] - self(self, left, right - 1));
        return dp[left][right] = res;
    };
    cout << MemoRec(MemoRec, 0, N) << endl;
}