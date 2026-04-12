#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    
    int n,i,j;
    cin >> n;
    long long int arr[n] , dp[n][n];
    for(i=0;i<n;i++){
    cin >> arr[i];
    dp[i][i] = arr[i];
    }
    
    for(i=1;i<n;i++){
        int x =0;
        for(j=i;j<n;j++,x++){
            dp[x][j] = max(arr[x] - dp[x+1][j] , arr[j] - dp[x][j-1]);
        }
    }
    cout << dp[0][n-1];
    return 0;
}