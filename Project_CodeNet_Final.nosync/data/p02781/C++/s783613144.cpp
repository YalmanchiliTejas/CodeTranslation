#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;
/* ちゃんと考えてわかって実装 */

int dp[105][4][3];

int main(void){
    string s; cin >> s;
    int KK; cin >> KK;

    int n = s.size();

    dp[0][0][0] = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<=KK; j++){
            for(int k=0; k<2; k++){
                int now_d = s[i] - '0';
                for(int d=0; d<10; d++){
                    // 次の状態に移る前に添字の準備
                    int next_i = i+1;
                    int next_j = j;
                    int next_k = k;
                    // d の値に応じて添字を修正
                    if(d!=0) next_j++;
                    if(next_j > KK) continue;
                    if(k == 0){
                        if(now_d < d) continue;
                        if(d < now_d) next_k = 1;
                    }
                    dp[next_i][next_j][next_k] += dp[i][j][k];
                }
            }
        }
    }
    cout << dp[n][KK][0] + dp[n][KK][1] << endl;
    return 0;
}