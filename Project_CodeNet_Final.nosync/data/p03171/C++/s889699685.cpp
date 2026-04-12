#include <bits/stdc++.h> 
using namespace std; 
typedef long long ll;
const int mxN=1e9;
const ll mod = 1e9+7;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;

    vector<ll> v(n);

    for(int i=0;i<n;i++) cin>>v[i];

    ll dp[n][n][2];

    for(int i=0;i<n;i++){
        dp[i][i][0] = v[i];
        dp[i][i][1] = 0;
    }

    for(int i=1;i<n;i++){
        for(int j=0;j+i<n;j++){
            if(dp[j+i][j+i][0]+dp[j][j+i-1][1]>dp[j][j][0]+dp[j+1][j+i][1]){
                dp[j][j+i][0]=dp[j+i][j+i][0]+dp[j][j+i-1][1];
                dp[j][j+i][1]=dp[j][j+i-1][0];
            }
            else{
                dp[j][j+i][0]=dp[j][j][0]+dp[j+1][j+i][1];
                dp[j][j+i][1]=dp[j+1][j+i][0];
            }
        }
    }

    cout<<dp[0][n-1][0]-dp[0][n-1][1];
}