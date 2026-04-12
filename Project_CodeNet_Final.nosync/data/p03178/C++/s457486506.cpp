#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <complex>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>

#define INF 100000000
#define MOD (int) (1e9+7)
#define rep(i, a) for (int i = 0; i < (a); i++)
using namespace std;

int main(){
    string K;
    int D;
    cin >> K >> D;

    long long int dp[10010][2][100];

    dp[0][0][0] = 1;

    for(int i = 0; i < K.size(); i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < D; k++){
                int lim;
                if(j == 1){
                    lim = 9;
                }else{
                    lim = K[i] - '0';
                }

                for(int d = 0; d < lim+1; d++){
                    dp[i+1][j || d < lim][(k+d)%D] += dp[i][j][k];
                    dp[i+1][j || d < lim][(k+d)%D] %= MOD;
                }
            }
        }
    }

    cout << (dp[K.size()][0][0]+dp[K.size()][1][0]-1+MOD)%MOD << endl;//答えに0が含まれるのでそれを除くために-1
}
