#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const ll mod = 1000000007;
const double eps = 1e-8;
const ll INF = 1e16;

#ifdef DEBUG
#include "inc/debug.hpp"
#else
#define debug(...) 42
#endif

template<typename A, size_t N, typename T>
void st_fill(A (&arr)[N], const T &val){ fill((T*)arr, (T*)(arr+N), val); }
void chmax(ll &a, ll b) { a = max(a, b); }

ll dp[200010][2][3];

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    for (int i=0; i<N; ++i) cin >> A[i];

    st_fill(dp, -INF);

    int r = 1 + (N % 2);
    dp[0][0][r-1] = 0;
    dp[0][1][r] = A[0];
    for (int i=1; i<N; ++i) {
        for (int j=0; j<3; ++j) {
            chmax(dp[i][1][j], dp[i-1][0][j] + A[i]);
            chmax(dp[i][0][j], dp[i-1][1][j]);
            if (j > 0) chmax(dp[i][0][j-1], dp[i-1][0][j]);
        }
    }

    ll res = -INF;
    for (int i=0; i<2; ++i) {
        for (int j=0; j<3; ++j) {
            res = max(res, dp[N-1][i][j]);
        }
    }
    cout << res << endl;

    return 0;
}