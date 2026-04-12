#include<algorithm>
#include<iostream>
#include<queue>
#include<string>
#include<vector>
using namespace std;
typedef long long ll;
const ll INF = 1000000000000000000;

string N;
ll K;
ll dp[110][5][2];

ll charNumberToLL(char c) {
    ll ret = c - '0';
    return ret;
}

int main() {
    cin >> N >> K;

    dp[0][0][0] = 1;

    for(int i=0; i<N.size(); i++){
        ll digit = charNumberToLL(N[i]);
        for(int j=0; j<=K; j++){
            for(int k=0; k<2; k++){
                for(int l=0; l<10; l++){
                    if(k == 0 && l > digit){
                        // Nを超えている。
                        continue;
                    }
                    if(l != 0){
                        // 0以外の数字を使用した。
                        if(l < digit || k == 1){
                            // Nを下回ることが確定。
                            dp[i+1][j+1][1] += dp[i][j][k];
                        } else {
                            // Nをこの時点で下回らない。
                            dp[i+1][j+1][0] += dp[i][j][k];
                        }
                    } else {
                        // 0を使用した。
                        if(l < digit || k == 1){
                            // Nを下回ることが確定。
                            dp[i+1][j][1] += dp[i][j][k];
                        } else {
                            // Nをこの時点で下回らない。
                            dp[i+1][j][0] += dp[i][j][k];
                        }
                    }

                }
            }
        }
    }

    cout << dp[N.size()][K][0] + dp[N.size()][K][1] << endl;
}