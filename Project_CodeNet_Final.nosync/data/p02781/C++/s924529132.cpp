#include "bits/stdc++.h"
#define REP(i, m, n) for(long long i = m; i < n; ++i)
#define CO(n) cout << n << endl
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

string S;
int K;
int dp[2][101][4];
//桁DP : dp[f][i][j]
//f:未満フラグ
//上からi桁目まで決めて0でない桁がj個

int main()
{
    ios::sync_with_stdio(false);
    cin >> S >> K;
    int l = S.length();
    //初期化
    //S[0]から始める
    dp[0][1][1] = 1;
    //S[0]-1,...,1から始める;
    dp[1][1][1] = (int)(S[0]-'0')-1;
    //0から始める
    dp[1][1][0] = 1;
    REP(i,1,l){
        int s = S[i]-'0'; //追加しようとしている桁に対応するNの数字
        //sが0の場合
        if (s == 0){
            //false tableの更新
            //0を追加する
            REP(j,0,4){
                dp[0][i+1][j] += dp[0][i][j];
            }
            ///true tableの更新
            //0を追加する
            REP(j,0,4){
                dp[1][i+1][j] += dp[1][i][j];
            }
            //1,...,9を追加する
            REP(j,0,3){
                dp[1][i+1][j+1] += 9*dp[1][i][j];
            }
        }
        //sが0でない場合
        else{
            //false tableの更新
            REP(j,0,3){
                //S[i]を追加する
                dp[0][i+1][j+1] = dp[0][i][j];
            }
            //true tableの更新
            REP(j,0,4){
                //0を追加する場合 //必ず未満フラグが立つ
                dp[1][i+1][j] = dp[0][i][j] + dp[1][i][j];
            }
            REP(j,0,3){
                //false table から S[i]-1,...,1 を追加する場合
                dp[1][i+1][j+1] += ((int)(S[i]-'0') - 1) * dp[0][i][j];
                //true table から 9,...,1 を追加する場合
                dp[1][i+1][j+1] += 9*dp[1][i][j];
            }
        }            
    }
    // CO("false");
    // REP(i,0,l+1){
    //     REP(j,0,4){
    //         cout << dp[0][i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    // CO("true");
    // REP(i,0,l+1){
    //     REP(j,0,4){
    //         cout << dp[1][i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    CO(dp[0][l][K]+dp[1][l][K]);
    return 0;
}