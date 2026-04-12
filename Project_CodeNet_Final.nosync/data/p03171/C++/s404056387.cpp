#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int N = 1e+5 + 1;

const int M = 1e+9 + 7;

int main() {
    int n;
    cin >> n;
    vector<vector<pair<ll, ll>>> dp(n+1, vector<pair<ll, ll>>(n+1));
    ll x;
    for(int i=1; i<=n; ++i){
        cin>>x;
        dp[i][i].first = (x);
        dp[i][i].second = 0;
    }
    for(int i= n-1; i>=1; --i){
        for(int j=i+1; j<=n; ++j){
            if(dp[i][i].first + dp[i+1][j].second > dp[j][j].first + dp[i][j-1].second){
                dp[i][j].first = dp[i][i].first + dp[i+1][j].second;
                dp[i][j].second =   dp[i+1][j].first;
            }
            else{
                dp[i][j].second =  dp[i][j-1].first;
                dp[i][j].first =  dp[j][j].first + dp[i][j-1].second;
            }
        }
    }
    cout<<dp[1][n].first - dp[1][n].second;
}