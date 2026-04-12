#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

typedef long long int ll;
const int N_MAX = 3005;
const int MOD = 998244353;
int A[N_MAX];
ll dp[N_MAX][N_MAX];
int N, S;

int main(){
    cin >> N >> S;
    for(int i = 1; i <= N; i++){
        cin >> A[i];
    }
    
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(int i = 1; i <= N; i++){
        dp[i][0] = (dp[i-1][0] + 1) % MOD;
        for(int j = 1; j < S; j++){
            if (A[i] > j)dp[i][j] = dp[i-1][j] % MOD;
            else{
                dp[i][j] = (dp[i-1][j-A[i]] + dp[i-1][j]) % MOD;
            }
        }
        if (S < A[i])dp[i][S] = dp[i-1][S] % MOD;
        else dp[i][S] = (dp[i-1][S] + dp[i-1][S-A[i]] * (N+1-i)) % MOD;
    }
    cout << dp[N][S] << endl;
    return 0;
}