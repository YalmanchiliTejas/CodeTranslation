#include <bits/stdc++.h>
using namespace std;
typedef pair<string, long long> P;
#define All(a) a.begin(), a.end()
string N;
int main(){
    string S;
    cin >> S;
    int K;
    cin >> K;
    vector<vector<vector<long long>>> dp(S.size(), vector<vector<long long>>(2, vector<long long> (K + 1, 0)));
    for(int i = 0; i < S.size(); i++){
        if(i == 0){
            dp[i][0][1] = S[i] - '1';
            dp[i][1][1] = 1;
        }
        else{
            for(int j = 0; j < K; j++){
                dp[i][0][K - j] = dp[i - 1][0][K - j] + dp[i - 1][0][K - j - 1] * 9;
                if(S[i] != '0'){
                    dp[i][0][K - j] += dp[i - 1][1][K - j] + dp[i - 1][1][K - j - 1] * (S[i] - '1');
                    dp[i][1][K - j] = dp[i - 1][1][K - 1 - j];
                }
                else dp[i][1][K - j] = dp[i - 1][1][K - j];
                if(j == K - 1) dp[i][0][K - j] += 9;
            }
        }
    }
    cout << dp[S.size() - 1][0][K] + dp[S.size() - 1][1][K] << endl;
}