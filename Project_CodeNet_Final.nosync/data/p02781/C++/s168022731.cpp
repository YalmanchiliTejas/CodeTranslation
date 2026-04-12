#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPR(i, n) for(int i = (int)(n); i >= 0; i--)
#define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int MOD = 1e9 + 7;

ll N,M,K,H,W;

int main(){
    string str;
    cin >> str >> K;
    int n = str.length();
    int dp[2][4][n+1];
    // 1 : obviously smaller than N
    for(int i = 0; i <= n; ++i){
      	for(int j = 0; j <= 1; ++j){
              for(int k= 0; k < 4; ++k){
                dp[j][k][i] = 0;
              }
        }
    }
    dp[0][0][0] = 1;
    for(int i = 1; i <= n; ++i){
        int num = str[i-1]- '0'; 
        dp[1][0][i] = 1;
        for(int k = 1; k < 4; ++k){

            dp[1][k][i] += 9 * dp[1][k-1][i-1] + dp[1][k][i-1];

            if(num == 0) dp[0][k][i] = dp[0][k][i-1];

            else{
                dp[0][k][i] = dp[0][k-1][i-1];
                dp[1][k][i] += dp[0][k][i-1] + dp[0][k-1][i-1] * (num-1);
            }

        }
    }
    cout << dp[0][K][n] + dp[1][K][n];
    return 0;
}

