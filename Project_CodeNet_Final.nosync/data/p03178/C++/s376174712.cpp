#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const int MOD = 1e9 + 7;

ll dp[10100][101][2];

signed main(){
    string K;
    int D;
    cin >> K;
    cin >> D;
    dp[0][0][0] = 1;
    int n = K.size();
    for(int digit = 0; digit < n; digit++){
        for(int d = 0; d < D; d++){
            for(int isless = 0; isless < 2; isless++){
                int c = K[digit] - '0';
                for(int next = 0; next < 10; next++){
                    if(next < c){
                        dp[digit + 1][(d + next) % D][1] += dp[digit][d][isless];
                        dp[digit + 1][(d + next) % D][1] %= MOD;
                    }else if(next == c){
                        dp[digit + 1][(d + next) % D][isless] += dp[digit][d][isless];
                        dp[digit + 1][(d + next) % D][isless] %= MOD;
                    }else{
                        if(isless == 1){
                            dp[digit + 1][(d + next) % D][isless] += dp[digit][d][isless];
                            dp[digit + 1][(d + next) % D][isless] %= MOD;
                        }
                    }
                }
            }
        }
    }
    cout << (dp[n][0][0] + dp[n][0][1] - 1 + MOD) % MOD << endl;
}