#include <bits/stdc++.h>
using namespace std;
 
const int INF = 1e9;
long long int dp[3000][3000][2];

int main() {

    int n;
    cin>>n;
    int a[n];
    for (int i=0; i<n; i++){
        cin>>a[i];
    }
    //dp[l][r][0] - value of X-Y when Taro start the game 
    //Initialize
    for (int i=0; i<n; i++){
        dp[i][i][0] = a[i];
        dp[i][i][1] = -a[i];
    }
    
    for (int l=n; l>=0; l--){
        for (int r=0; r<n; r++){
            if (r>l){
                dp[l][r][0] = max(a[l]+dp[l+1][r][1], a[r]+dp[l][r-1][1]);
                dp[l][r][1] = min(dp[l+1][r][0]-a[l], dp[l][r-1][0]-a[r]);
            }
        }
    }

    // ans - dp[0][n-1][0] - value of X-Y for complete array when Taro starts
    cout<<dp[0][n-1][0];
    return 0;
}


