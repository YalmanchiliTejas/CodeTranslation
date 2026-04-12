#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    long long a[n];
    for(int i=0; i<n; i++) cin >> a[i];
    if(n == 2){
        cout << max(a[0],a[1]) << endl;
        return 0;
    }
    if(n == 3){
        cout << max(a[0],max(a[1],a[2])) << endl;
        return 0;
    }
    long long dp[4][n/2];
    dp[0][0] = a[1];
    dp[1][0] = a[0];
    for(int i=1; i<n/2; i++){
        dp[0][i] = max(dp[0][i-1],dp[1][i-1]) + a[2*i+1];
        dp[1][i] = dp[1][i-1] + a[2*i];
    }
    dp[2][1] = a[3];
    dp[3][1] = max(a[0],max(a[1],a[2]));
    for(int i=2; i<n/2; i++){
        dp[2][i] = max(dp[0][i-2],max(dp[1][i-2],max(dp[2][i-1],dp[3][i-1]))) + a[i*2+1];
        dp[3][i] = max(dp[0][i-2],max(dp[1][i-2],dp[3][i-1])) + a[2*i];
    }
    long long t = max(dp[0][n/2-1],dp[1][n/2-1]);
    if(n%2==0) cout << t << endl;
    else cout << max(t,a[n-1]+dp[3][n/2-1]) << endl;
    return 0;
}
