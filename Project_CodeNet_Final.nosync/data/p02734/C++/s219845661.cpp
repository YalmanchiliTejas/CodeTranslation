#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <bitset>
#include <utility>
#include <queue>
#include <deque>

using namespace std;

int main(){

    constexpr int modulo = 998244353;
    int N, S;
    cin >> N >> S;
    int a, r, t;
    int tmp[3][2];
    vector<vector<vector<int>>> dp(3010, vector<vector<int>>( 3010, vector<int>(3, 0)));

    cin >> a;
    for(r=0;r<=S;++r){
        for(t=0;t<3;++t){
            if(r==0) dp[0][r][t] = 1;
            if(r <= S and r==a) dp[0][r][t] = 1;
        }       
    }
    
    for(int i=0;i<N-1;++i){
        cin >> a;
        for(r=0;r<=S;++r){
            // aを選ばない 
            tmp[0][0] = dp[i][r][0];

            if(r==0) tmp[1][0] = (dp[i][r][1] + 1) % modulo;
            else tmp[1][0] = dp[i][r][1];

            tmp[2][0] = (dp[i][r][2] + tmp[1][0]) % modulo;

            for(t=0;t<3;++t){
                dp[i+1][r][t] = (dp[i+1][r][t] + tmp[t][0]) % modulo;
            }

            // aを選ぶ 
            if(r+a > S) continue;
            tmp[0][1] = dp[i][r][0];

            if(r==0) tmp[1][1] = (dp[i][r][1] + 1) % modulo;
            else tmp[1][1] = dp[i][r][1];

            tmp[2][1] = tmp[1][1];

            for(t=0;t<3;++t){
                dp[i+1][r+a][t] = (dp[i+1][r+a][t] + tmp[t][1]) % modulo;
            }

        }
    }

    // for(int i=0;i<N;++i){
    //     for(r=0;r<=S;++r){
    //         for(t=0;t<3;++t){
    //             printf("dp[%3d][%3d][%d] = %d\n", i, r, t, dp[i][r][t]);
    //         }
    //     }
    // }

    cout << dp[N-1][S][2] << endl;
    
    return 0;
}
