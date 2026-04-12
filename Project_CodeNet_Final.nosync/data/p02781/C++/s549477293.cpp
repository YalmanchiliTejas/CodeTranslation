#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

const long MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;

int main(){
    string S;
    cin >> S;

    int K;
    cin >> K;

    if(S.length() < K){
        cout << 0 << endl;
        return 0;
    }

    int dp[S.length()+1][S.length()+1][2];
    for(int i=0; i<=S.length(); i++){
        for(int j=0; j<=S.length(); j++){
            dp[i][j][0] = 0;
            dp[i][j][1] = 0;
        }
    }
    dp[0][0][0] = 1;

    for(int i=0; i<S.length(); i++){
        for(int j=0; j<S.length(); j++){
            int d = S[i] - '0'-1;
            if(S[i]=='0'){
                dp[i+1][j][0] += dp[i][j][0];
            }else{
                dp[i+1][j+1][0] += dp[i][j][0];
                dp[i+1][j+1][1] += dp[i][j][0]*d;
                dp[i+1][j][1] += dp[i][j][0];
            }
            dp[i+1][j][1] += dp[i][j][1];
            dp[i+1][j+1][1] += dp[i][j][1]*9;
        }
    }

    cout << dp[S.length()][K][0]+dp[S.length()][K][1] << endl;


    return 0;
}
