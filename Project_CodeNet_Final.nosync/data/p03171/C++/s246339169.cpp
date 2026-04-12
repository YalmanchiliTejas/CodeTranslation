#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for(int(i) = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for(int(i) = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define pb push_back
#define MP(a, b) make_pair((a), (b))
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;

ll rec(int l, int r, int is_first, vector<ll> &A, vector<vector<ll>> &dp) {
    if(dp[l][r] != LINF)
        return dp[l][r];
    if(l >= r)
        return dp[l][r] = 0;
    if(is_first) {
        return dp[l][r] = max(rec(l, r - 1, !is_first, A, dp) + A[r - 1],
                              rec(l + 1, r, !is_first, A, dp) + A[l]);
    } else {
        return dp[l][r] = min(rec(l, r - 1, !is_first, A, dp) - A[r - 1],
                              rec(l + 1, r, !is_first, A, dp) - A[l]);
    }
}

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) { cin >> A[i]; }
    vector<vector<ll>> dp(N + 1, vector<ll>(N + 1, LINF));
    // dp[i][j]:=[i,j)から始めたときのX-Yの値
    cout << rec(0, N, 1, A, dp) << endl;
    return 0;
}