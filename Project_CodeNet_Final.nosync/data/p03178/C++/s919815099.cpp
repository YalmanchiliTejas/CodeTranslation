#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;
ll dp[2][100001][100];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    string K;
    int D;
    dp[0][0][0] = 1;
    dp[1][0][0] = 1;
    cin >> K >> D;
    for(int i = 0; i < K.size(); i++){
        int m = K[K.size()-i-1]-'0';
        for(int j = 0; j < D; j++){
            for(int k = 0; k < 10; k++){
                if(k < m){
                    dp[0][i+1][(j+k)%D] += dp[1][i][j];
                }else if(k == m){
                    dp[0][i+1][(j+k)%D] += dp[0][i][j];
                }
                dp[1][i+1][(j+k)%D] += dp[1][i][j];
                dp[0][i+1][(j+k)%D] %= MOD;
                dp[1][i+1][(j+k)%D] %= MOD;
            }
        }
    }
    dp[0][K.size()][0]--;
    dp[0][K.size()][0] += MOD;
    dp[0][K.size()][0] %= MOD;
    cout << dp[0][K.size()][0] << endl;
}