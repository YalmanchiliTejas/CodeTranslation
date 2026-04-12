#include <iostream>
#include <string>
using namespace std;
using ll = long long;

ll dp[110][2][110];

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    string s;
    int K;
    cin >> s >> K;
    
    int n = s.size();
    dp[0][0][0] = 1;
    for(int i = 0; i < n; ++i){
        int D = s[i] - '0';
        for(int j = 0; j < 2; ++j){
            for(int k = 0; k < K+5; ++k){
                for(int d = 0; d <= (j? 9: D); ++d){
                    dp[i+1][j||(d<D)][k+(d!=0)] += dp[i][j][k];
                }
            }
        }
    }

    cout << dp[n][0][K] + dp[n][1][K] << endl;


    return 0;
}