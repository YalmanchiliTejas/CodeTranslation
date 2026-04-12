#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

int main() {
    ll n,i,j;
    cin >> n;
    vector<ll> v(n + 1);
    for(i = 1; i <= n; i++) {
        cin >> v[i];
    }
    ll dp[n + 1][n + 1];
    for(i = 1; i <= n;i++){
        for(j = 1; j <= n - i; j++) {
            if(n % 2 == i % 2)dp[j][j + i - 1] = -1e13;
            else dp[j][j + i - 1] = 1e13;
        }
    }
    for(i = 0; i <= n;i++){
        if(n % 2 == 1) dp[i][i] = v[i];
        else dp[i][i] = -v[i];
    }
    for(i = 2; i <= n;i++){
        for(j = 1; j <= n - i + 1; j++){
            if(n % 2 == i % 2) {
                // 先手
                dp[j][j + i - 1] = max(dp[j + 1][j + i - 1] + v[j], dp[j][j + i - 2] + v[j + i - 1]);
            }
            else{
                // 後手
                dp[j][j + i - 1] = min(dp[j + 1][j + i - 1] - v[j], dp[j][j + i - 2] - v[j + i - 1]);
            }
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}