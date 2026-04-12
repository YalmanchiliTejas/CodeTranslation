#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
using Graph = vector<vector<int>>;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;


ll dp[100010][101][2];

int main(){
    string K;
    cin >> K;
    int d;
    cin >> d;
    dp[0][0][1] = 1;

    int n = K.size();

    for(int i = 1; i <= n; i++){
        rep(j, d){
            int digit = K[i - 1] - '0';
            rep(k, 10){
                dp[i][j][0] += dp[i - 1][((j - k)%d + d) % d][0];
                if (k < digit) dp[i][j][0] += dp[i - 1][((j - k)%d + d) % d][1];
                dp[i][j][0] %= MOD;
            }
            dp[i][j][1] = dp[i - 1][((j - digit)%d + d) % d][1];
            dp[i][j][0] %= MOD;
        }
    }

    cout << (dp[n][0][0] + dp[n][0][1] - 1 + MOD) % MOD << endl;

    return 0;
}