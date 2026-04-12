#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n] = {};
    for(int i=0; i<n; i++) cin >> a[i];
    long long dp[n+1][n+1] = {};
    for(int len=1; len<=n; len++){
        for(int i=0; i+len<=n; i++){
            int j = i+len;
            if ((n - len) % 2 == 0)
                dp[i][j] = max(dp[i+1][j] + a[i], dp[i][j-1] + a[j-1]); // first
            else
                dp[i][j] = min(dp[i+1][j] - a[i], dp[i][j-1] - a[j-1]); // second
                
           /* if((n - len) % 2 != 0){
                dp[i][j+1] = max(dp[i][j+1], a[j] + dp[i][j]);
                if(i>0) dp[i-1][j] = max(dp[i-1][j], a[i-1] + dp[i][j]);
            }else{
                 dp[i][j+1] = min(dp[i][j+1], -a[j] + dp[i][j]);
                if(i>0) dp[i-1][j] = min(dp[i-1][j], -a[i-1] + dp[i][j]);
            } */
        }
    /*    for(int i=0; i<n; i++){
            for(int j=0; j<=n; j++) cout << dp[i][j] << " ";
            cout << endl;
        }
        cout << endl;*/
    }
    cout << dp[0][n] << endl;
    return 0;
}