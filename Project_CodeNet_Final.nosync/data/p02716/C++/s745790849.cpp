#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long int ll;
typedef pair<int, int> P;

const ll INF = -1e18;
int n;

vector<ll> a(202020);
vector<vector<ll>> dp(3, vector<ll>(202020, INF));

int main()
{
    cin >> n;
    rep(i, n) cin >> a[i];
  	
    rep(i, 3) dp[i][i] = a[i];
    for(int i = 0; i < n - 2; i++)
    {
        
        dp[0][i + 2] = max(dp[0][i + 2], dp[0][i] + a[i + 2]);
        dp[1][i + 3] = max(dp[1][i + 3], dp[0][i] + a[i + 3]);
        dp[2][i + 4] = max(dp[2][i + 4], dp[0][i] + a[i + 4]);
        
        dp[1][i + 2] = max(dp[1][i + 2], dp[1][i] + a[i + 2]);
        dp[2][i + 3] = max(dp[2][i + 3], dp[1][i] + a[i + 3]);
        

        dp[2][i + 2] = max(dp[2][i + 2], dp[2][i] + a[i + 2]);
    }

    
    ll res = INF;
    if(n % 2 == 1)
    {
        res = max(res, dp[0][n - 3]);
        res = max(res, dp[1][n - 2]);
        res = max(res, dp[2][n - 1]);
    }
    else
    {
        res = max(res, dp[0][n - 2]);
        res = max(res, dp[1][n - 1]);
    }
    
    cout << res << endl;

    
    return 0;
}
