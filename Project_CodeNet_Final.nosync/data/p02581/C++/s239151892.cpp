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

int dp[2005][2005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> A(N * 3);
    for(int i = 0; i < N * 3; ++i){
        cin >> A[i];
        --A[i];
    }

    for(int i = 0; i <= N; ++i){
        for(int j = 0; j <= N; ++j){
            dp[i][j] = -INF;
        }
    }
    auto update = [&](int i, int j, int val) -> void {
        chmax(dp[i][j], val);
        chmax(dp[j][i], val);
        chmax(dp[i][N], val);
        chmax(dp[N][i], val);
        chmax(dp[j][N], val);
        chmax(dp[N][j], val);
        chmax(dp[N][N], val);
    };
    update(A[0], A[1], 0);

    int score = 0;
    for(int i = 2; i < N * 3 - 1; i += 3){
        int p = A[i], q = A[i + 1], r = A[i + 2];
        if(p == q && q == r){
            ++score;
            continue;
        }
        vector<tuple<int, int, int>> que;
        for(int loop = 0; loop < 3; ++loop){
            que.emplace_back(p, q, max(dp[N][N], dp[r][r] + 1));
            swap(p, q);
            swap(q, r);
        }
        for(int x = 0; x < N; ++x){
            for(int loop = 0; loop < 3; ++loop){
                int val = dp[x][N];
                if(p == q)  chmax(val, dp[x][p] + 1);
                que.emplace_back(x, r, val);
                swap(p, q);
                swap(q, r);
            }
        }
        for(auto& tup : que){
            int idx1, idx2, val;
            tie(idx1, idx2, val) = tup;
            update(idx1, idx2, val);
        }
    }

    int ans = max(dp[N][N], dp[A.back()][A.back()] + 1);
    ans += score;
    cout << ans << endl;
}