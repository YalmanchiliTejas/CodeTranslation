#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;
typedef long long ll;

ll solveDP(vector<ll> v){
    int n = v.size();
    vector<vector<ll>> dp(n, vector<ll>(n));

    for(int i = 0; i < n; i++)
        dp[i][i] = v[i];

    for(int len = 2; len <= n; len++){
        for(int i = 0; i <= n - len; i++){
            int j = i + len - 1;
            dp[i][j] = max((-1 * dp[i][j-1]) + dp[j][j], (-1 * dp[i+1][j]) + dp[i][i]);
        }
    }

    return dp[0][n-1];
}

int main(){
    fastio;
    ll n;
    cin>>n;

    vector<ll> v(n);

    for(ll & x : v)
        cin>>x;

    // cout<<solverec(v, 0, v.size()-1, 0)<<endl;
    cout<<solveDP(v)<<endl;

    return 0;
}