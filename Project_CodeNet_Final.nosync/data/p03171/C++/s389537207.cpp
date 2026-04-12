#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    if(n==1){
        cout << a[0];
        return 0;
    }    
    vector<vector<long long int>> dp(n,vector<long long int>(n,0));
    for(int k=0;k<n;k++){
        for(int j=k,i=0;i<n&&j<n;i++,j++){
            if(i==j) dp[i][j] = a[i];
            else if(j-i==1) dp[i][j] = max(a[i],a[j]);
            else dp[i][j] = max( min( dp[i+2][j] , dp[i+1][j-1] )+a[i], min( dp[i+1][j-1],dp[i][j-2] )+a[j] );
        }
    }
    if(dp[1][n-1] < dp[0][n-2]) cout << dp[0][n-1] - dp[1][n-1];
    else cout << dp[0][n-1] - dp[0][n-2];
	return 0;
}