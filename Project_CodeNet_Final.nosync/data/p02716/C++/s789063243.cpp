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
// constexpr int mod = 1000000007;
constexpr int mod = 998244353;

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
    int M = 1 + (N & 1);
    constexpr ll inf = 1e+17;
    // (is_used, max(unused - used))
    vector<vector<ll>> dp(2, vector<ll>(M + 1, -inf));
    dp[0][0] = 0;
    for(int loop = 0; loop < N; ++loop){
        int A;
        cin >> A;
        vector<vector<ll>> nxt_dp(2, vector<ll>(M + 1, -inf));
        for(int i = 0; i < 2; ++i){
            for(int j = 0; j <= M; ++j){
                if(dp[i][j] == -inf)    continue;
                if(i)   chmax(nxt_dp[0][j], dp[1][j]);
                else{
                    if(j < M)   chmax(nxt_dp[0][j + 1], dp[0][j]);
                    chmax(nxt_dp[1][j], dp[0][j] + A);
                }
            }
        }
        dp = move(nxt_dp);
    }
    ll ans = -inf;
    for(int i = 0; i < 2; ++i){
        for(int j = (N & 1 ? 1 : 0); j <= M; ++j){
            chmax(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
}