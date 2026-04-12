#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    string n;
    cin >> n;
    long int k;
    cin >> k;
    long int dp[n.size()][k+1][2];
    dp[0][0][0] = 0;
    dp[0][0][1] = 1;
    dp[0][1][0] = 1;
    dp[0][1][1] = n[0] - '1';
    for (int i = 2; i <= k; i++){
        dp[0][i][0] = 0;
        dp[0][i][1] = 0;
    }
    for (int i = 1; i < n.size(); i++){
        for (int j = 0; j <= k; j++){
            if (n[i] == '0'){
                dp[i][j][0] = dp[i-1][j][0];
                if (j == 0){
                    dp[i][j][1] = dp[i-1][j][1];
                }else{
                    dp[i][j][1] = dp[i-1][j-1][1] * 9 + dp[i-1][j][1];
                }
            }else{
                if (j == 0){
                    dp[i][j][0] = 0;
                    dp[i][j][1] = dp[i-1][j][1] + dp[i-1][j][0];
                }else{
                    dp[i][j][0] = dp[i-1][j-1][0];
                    dp[i][j][1] = dp[i-1][j-1][1] * 9 + dp[i-1][j][1] + dp[i-1][j-1][0] * (n[i] - '0' - 1) + dp[i-1][j][0];
                }
            }
        }
    }
    // rep(i, n.size()){
    //     rep(j, k + 1){
    //         cout << dp[i][j][0] << " ";
    //     }cout << endl;
    // }

    // rep(i, n.size()){
    //     rep(j, k + 1){
    //         cout << dp[i][j][1] << " ";
    //     }cout << endl;
    // }
    cout << dp[n.size()-1][k][1] + dp[n.size()-1][k][0] << endl;
}
