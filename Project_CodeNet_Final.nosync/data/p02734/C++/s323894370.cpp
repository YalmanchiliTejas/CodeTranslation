#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define pb push_back

int n, s;
int const N = 3e3 + 10, M = 998244353;
int a[N];
int dp[N][2 * N][3];

signed main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);    
    cin >> n >> s;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }
    
    int ans = 0;
    dp[n + 1][s][2] = 1;
    for(int i = n ; i >= 1 ; i--){
        for(int sum = s ; sum >= 0 ; sum --){
            for(int t = 0 ; t <= 2 ; t++){
                if(t == 0) {
                    dp[i][sum][0] = (dp[i + 1][sum][0] + dp[i + 1][sum + a[i]][1] + dp[i + 1][sum][1]) % M;
                }
                else if( t == 1){
                    dp[i][sum][1] = (dp[i + 1][sum][1] + dp[i + 1][sum + a[i]][1] + dp[i + 1][sum + a[i]][2] + dp[i + 1][sum][2]) % M;
                }
                else{
                    dp[i][sum][2] = dp[i + 1][sum][2] % M;
                }
            }
        }
        (ans += dp[i][0][1]) %= M;
    }
    cout << ans << endl;
    return 0;
}