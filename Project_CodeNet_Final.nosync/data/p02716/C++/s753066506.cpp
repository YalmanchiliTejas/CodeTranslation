#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using bint = boost::multiprecision::cpp_int;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define repSE(i,s,n) for (int i = (s); i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF = 1e18;
ll dp[200002][4];

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i,N) cin >> A[i];
    int k = 1 + N%2;
    rep(i,N+1) rep(j,k+1) dp[i][j] = -INF;
    dp[0][0] = 0;
    rep(i,N) rep(j,k+1) {
        dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]);
        ll now = dp[i][j];
        if ((i+j)%2 == 0) now += A[i];
        dp[i+1][j] = max(dp[i+1][j], now);
    }
    cout << dp[N][k] << endl;
    return 0;
}
