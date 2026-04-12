#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
//typedef pair<int,int> P;
typedef tuple<int,int,int> T;
ll INFL = 1000000000000000010;//10^18 = 2^60
int INF = 2147483600;//10^9
ll MOD  = 1000000007;
int D;
string S;
void solve(){
    int N[S.size()];
    for(int i = 0; i < S.size(); i++){
        N[i] = S.at(i) - '0';
    }
    ll dp[2][D][2];
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    for(int i = 0; i < S.size(); i++){
        int d = N[i];
        for(int j = 0; j < D; j++){
            if(d == 0){
                dp[1][j][0] += dp[0][j][0];
                for(int k = 0; k < 10; k++){
                    dp[1][j][1] += dp[0][(((j-k)+D)%D+D)%D][1];
                    dp[1][j][1] %= MOD;
                }
            }
            else{
                for(int k = 0; k < 10; k++){
                    dp[1][j][1] += dp[0][(((j-k)+D)%D+D)%D][1];
                    dp[1][j][1] %= MOD;
                }
                for(int k = 0; k < d; k++){
                    dp[1][j][1] += dp[0][(((j-k)+D)%D+D)%D][0];
                    dp[1][j][1] %= MOD;
                }
                dp[1][j][0] += dp[0][(((j-d)+D)%D+D)%D][0];
                dp[1][j][0] %= MOD;
            }
            
        }
        for(int j = 0; j < D; j++){
            for(int k = 0; k < 2; k++){
                dp[0][j][k] = dp[1][j][k];
            }
        }
        
        for(int j = 0; j < D; j++){
            for(int k = 0; k < 2; k++){
                dp[1][j][k] = 0;
            }
        }
        
    }
    cout << (((dp[0][0][0] + dp[0][0][1] - 1) % MOD) + MOD) % MOD << endl;
}
int main(void){
    cin >> S >> D;
    solve();
    
}
