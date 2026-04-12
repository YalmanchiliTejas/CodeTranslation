#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#include <functional>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define REP(i, n) for (int i = 1; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
using namespace std;
using ll = long long;
constexpr int inf = 1000000000;
constexpr ll INF = 5000000000000000000;

template <typename T> bool chmax(T &a, T b) {if (a < b) {a = b; return true;} return false;}

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    if (N == 2) {
        cout << max(A[0], A[1]) << "\n";
        return 0;
    }
    
    vector<vector<ll>> dp(N, vector<ll>(3, -INF));
    dp[0][0] = A[0];
    dp[1][1] = A[1];
    dp[2][0] = A[0] + A[2];
    dp[2][2] = A[2];
    for (int i = 3; i < N; ++i) {
        if (i % 2 == 0) {
            chmax(dp[i][0], dp[i - 2][0] + A[i]);
            chmax(dp[i][2], dp[i - 2][2] + A[i]);
            chmax(dp[i][2], dp[i - 3][1] + A[i]);
        } else {
            chmax(dp[i][1], dp[i - 2][1] + A[i]);
            chmax(dp[i][1], dp[i - 3][0] + A[i]);
        }
    }
    
    if (N % 2 == 0) {
        cout << max(dp[N - 2][0], dp[N - 1][1]) << "\n";
    } else {
        cout << max({dp[N - 3][0], dp[N - 2][1], dp[N - 1][2]}) << "\n";
    }
    return 0;
}
