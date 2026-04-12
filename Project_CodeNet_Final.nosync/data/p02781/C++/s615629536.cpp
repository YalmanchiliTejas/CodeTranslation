#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e18;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int dp[105][5][2];
signed main() {
    string N;
    int K;
    cin >> N >> K;
    for(int i = 0; i < N.size(); i++) {
        if(i == 0) {
            dp[i][1][0] = 1;
            dp[i][0][1] = 1;
            dp[i][1][1] = N[i]-'1';
            continue;
        }
        for(int j = 0; j <= K; j++) {
            if(N[i]-'0' >= 1) {
                dp[i][j][1] += dp[i-1][j][0]+dp[i-1][j][1];
                if(j-1 >= 0) {
                    dp[i][j][0] += dp[i-1][j-1][0];
                    dp[i][j][1] += dp[i-1][j-1][0]*(N[i]-'1')+dp[i-1][j-1][1]*9;
                }
            }
            else {
                dp[i][j][0] += dp[i-1][j][0];
                dp[i][j][1] += dp[i-1][j][1];
                if(j-1 >= 0) {
                    dp[i][j][1] += dp[i-1][j-1][1]*9;
                }
            }
        }
    }
    cout << dp[N.size()-1][K][0]+dp[N.size()-1][K][1] << endl;
}