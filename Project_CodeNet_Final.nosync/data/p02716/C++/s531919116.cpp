#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000
#define int long long
int dp[200010][3];
int A[200010];
int N; 
int calc(int x, int k, int choice) {
    if (x >= N) return -INF2;
    else if ((x == N - 1 || x == N - 2) && choice == N/2 - 1) return A[x];
    if(dp[x][k] != -INF2) return dp[x][k];
    if(k == 0)
        return dp[x][k] = A[x] + calc(x + 2, k, choice + 1);
    else if(k == 1)
        return dp[x][k] = A[x] + max(calc(x + 2, k, choice + 1), calc(x + 3, k - 1, choice + 1)); 
    else
        return dp[x][k] = A[x] + max({calc(x + 2, k, choice + 1), calc(x + 3, k - 1, choice + 1), calc(x + 4, k - 2, choice + 1)});
}

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    
    rep(i, N) cin >> A[i];
    int K = 1;
    if (N % 2 == 1) K++;
    rep(i, 200010) rep(j, 3) dp[i][j] = -INF2;
    if (K == 1)
        cout << max({calc(0, K, 0), calc(1, K - 1, 0)}) << endl;
    else
        cout << max({calc(0, K, 0), calc(1, K - 1, 0), calc(2, K - 2, 0)}) << endl;
    return 0;
}
