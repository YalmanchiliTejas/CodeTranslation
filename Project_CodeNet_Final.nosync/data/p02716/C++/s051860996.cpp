#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>

typedef long long ll;
const ll MOD = 1e9 + 7;
const long long INF = 1LL<<60;

using namespace std;

ll dp[200020][3];

int main(){
    std::ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < n+10; i++){
        for(int j = 0; j < 3; j++){
            dp[i][j] = -INF;
        }
    }

    dp[0][1] = a[0];
    dp[0][0] = 0;
    dp[0][2] = 0;
    dp[1][1] = a[0];
    dp[1][0] = a[1];
    dp[1][2] = 0;
    for(int i = 2; i < n; i++){
        if(i%2 == 0){
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
            dp[i][1] = dp[i-1][2]+a[i];
            dp[i][2] = dp[i-1][1]+a[i];
        } else {
            dp[i][0] = dp[i-1][0]+a[i];
            dp[i][1] = dp[i-1][2];
            dp[i][2] = max(dp[i-1][1],dp[i-1][0]);
        }
    }
    ll ans = max(dp[n-1][0],dp[n-1][1]);
    cout << ans << endl;

    return 0;
}