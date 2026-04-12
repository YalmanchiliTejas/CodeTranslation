#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(s,i, n) for (int i = (int)s; i < (int)(n); i++)
#define pb push_back
typedef long long ll;

#define max_n 3001
#define INF 1e15

ll  f(int i, int j, int N, vector<ll> &a, vector<vector<ll>> &dp){
    if (dp[i][j] != INF) return dp[i][j];

    int turn = N - (j - i);
    ll d;
    if (turn % 2 == 0) {
        d = max(f(i + 1, j, N, a, dp) + a[i], f(i, j - 1, N, a, dp) + a[j - 1]);
    }
    if (turn % 2 == 1) {
        d = min(-a[i] + f(i + 1, j, N, a, dp), -a[j - 1] + f(i, j - 1, N, a, dp));
    }

    return dp[i][j] = d;
}

int main(){
    int n;
    cin>>n;
    vector<ll> a(n);
    rep(i,n)cin>>a[i];

    vector<vector<ll>> dp(n+1, vector<ll>(n+1,INF));
    for (int i = 0; i <= n; i++) dp[i][i] = 0;
    f(0, n, n, a, dp);
    cout << dp[0][n] << endl;

    return 0;
}