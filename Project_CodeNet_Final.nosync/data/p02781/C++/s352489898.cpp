#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    string S;
    cin >> S;
    int K;
    cin >> K;
    int n = S.length();
    long dp[n+1][2][K+1];
    for(int i=0; i<n+1; i++){
        for(int s=0; s<2; s++){
            for(int j=0; j<K+1; j++){
                dp[i][s][j] = 0;
            }
        }
    }
    dp[0][0][0] = 1;
    for(int i=1; i<n+1; i++){
        int n = S[i-1] - '0';
        for(int j=0; j<K+1; j++){
            for(int s=0; s<2; s++){
                for(int x=0; x<=(s? 9 : n); x++){
                    if(j!=0)  dp[i][s || x < n][j] += dp[i-1][s][x==0 ? j : j-1];
                    else      dp[i][s || x < n][0] += (x == 0 ? dp[i-1][s][0] : 0) ;
                }
            }
        }
    }
    cout << dp[n][1][K] + dp[n][0][K] << endl;
    return 0;
}
