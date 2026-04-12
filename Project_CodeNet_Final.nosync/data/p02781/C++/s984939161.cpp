#include <iostream>

using namespace std;

int main(){
    string S;
    cin >> S;
    int K;
    cin >> K;

    long dp[S.length()][5][2];
    for(int i=0; i<S.length(); i++){
        for(int j=0; j<4; j++){
            for(int k=0; k<2; k++){
                dp[i][j][k] = 0;
            }
        }
    }
    dp[0][1][0] = 1;
    dp[0][1][1] = S[0]-'0'-1;
    dp[0][0][1] = 1;
    // 0: t
    // 1: >t
    for(int i=1; i<S.length(); i++){
        for(int j=0; j<4; j++){
            if(S[i]=='0'){
                dp[i][j][0] = dp[i-1][j][0];
            }else{
                dp[i][j+1][0] = dp[i-1][j][0];
                dp[i][j+1][1] += dp[i-1][j][0]*(S[i]-'0'-1);
                dp[i][j][1] += dp[i-1][j][0];
            }

            dp[i][j+1][1] += dp[i-1][j][1]*9;
            dp[i][j][1] += dp[i-1][j][1];
        }
    }

    cout << dp[S.length()-1][K][0] + dp[S.length()-1][K][1] << endl;

    return 0;
}