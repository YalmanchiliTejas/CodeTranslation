#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)

const int MOD = 1e+9 + 7;

int main()
{
    string K;
    cin >> K;
    int D;
    cin >> D;

    int N = K.size();

    // dp[i][j]: 上から i 桁目まで決めたときに D で割った余りが j になるような場合の数
    vector<vector<long long>> dp(N, vector<long long>(D)), dp_max(N, vector<long long>(D));
    // initialize
    dp_max[0][(int)(K[0]-'0')%D] = 1;
    REP(j, (int)(K[0]-'0')) dp[0][j%D] += 1;
    // dp
    FOR(i, 1, N){
        int tmp = (int)(K[i]-'0');
        REP(j, D){
            dp_max[i][(j+tmp)%D] += dp_max[i-1][j];
            REP(k, 10){
                dp[i][(j+k)%D] += dp[i-1][j];
                if(k < tmp) dp[i][(j+k)%D] += dp_max[i-1][j];
                dp[i][(j+k)%D] %= MOD;
            }
        }
    }
    cout << (dp[N-1][0]+dp_max[N-1][0]-1+MOD)%MOD << endl;  // 全部 0 を引くのを忘れずに

    return 0;
}