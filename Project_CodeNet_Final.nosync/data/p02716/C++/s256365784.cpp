#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false), cin.tie(0)
#define debug(a) cout << #a ": " << a << endl
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;
ll a[N], dp[N][2];
int main(void){
    IOS;
    int n; cin >> n; 
    for (int i = 1; i <= n; ++i) cin >> a[i];
    dp[2][0] = a[1], dp[2][1] = a[2];
    for (int i = 3; i <= n; ++i){
        if (i%2 == 1){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = a[i]+max(max(dp[i-2][1], dp[i-2][0]), max(dp[i-3][1], dp[i-3][0]));
        }else{
            dp[i][0] = a[i-1]+dp[i-2][0];
            dp[i][1] = a[i]+max(dp[i-1][0], max(dp[i-2][0], dp[i-2][1]));
        }
    }
    cout << max(dp[n][0], dp[n][1]) << endl;
    return 0;
}