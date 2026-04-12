#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

ll N,S;
ll A[3005];

ll mod = 998244353;

ll dp[3005][3005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> S;

    for (int i = 0;i < N;i++){
        cin >> A[i];
    }

    for (int i = 0;i < N;i++){
        dp[i+1][A[i]] += i+1;
        for (int j = 0;j <= S;j++){
            dp[i][j] %= mod;
            dp[i+1][j] += dp[i][j];
            dp[i+1][j] %= mod;
            if(j+A[i] <= S){ 
                dp[i+1][j+A[i]] += dp[i][j];
                dp[i+1][j+A[i]] %= mod;
            }
        }
    }

    ll ans = 0;
    for (int i = 0;i <= N;i++){
        ans += dp[i][S];
        ans %= mod;
    }

    cout << ans << endl;

    return 0;

}