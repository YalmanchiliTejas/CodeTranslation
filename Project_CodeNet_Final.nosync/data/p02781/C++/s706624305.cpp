#include <iostream>
#include <vector>
#include <string>
#include <memory.h>
using namespace std;
typedef long long ll;

int main(){
    string s;
    int K;
    cin >> s >> K;
    int N = s.size();
    int dp[N + 1][2][K + 5];
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;

    for (int i = 0; i < N;i++){
        for (int j = 0; j < 2;j++){
            for (int k = 0; k < K + 1;k++){
                int t = j ? 9 : s[i] - '0';
                for (int l = 0; l < t + 1;l++){
                    dp[i + 1][j || l < t][k + (l != 0)] += dp[i][j][k];
                }
            }
        }
    }
    cout << dp[N][0][K] + dp[N][1][K] << endl;
    return 0;
}