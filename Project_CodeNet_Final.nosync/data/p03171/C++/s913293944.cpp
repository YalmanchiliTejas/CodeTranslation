#include <bits/stdc++.h>

using namespace std;

const int N = 3e3+100;

long long int dp[N][N][3], a[N];

int main () {
    long long int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++ ) {
        cin >> a[i];
        dp[i][i][0]=a[i];
        dp[i][i][1]=0;
    }
    for(int d = 1 ; d < n ; d++ ) {
        for(int j = 0 ; j < n ; j++ ) {
            if(j+d>=n)break;
            int i = j+d;
            dp[j][i][0]=max(dp[j][i-1][1]+a[i],dp[j+1][i][1]+a[j]);
            dp[j][i][1]=min(dp[j][i-1][0],dp[j+1][i][0]);
        }
    }
    cout << dp[0][n-1][0]-dp[0][n-1][1];
}
