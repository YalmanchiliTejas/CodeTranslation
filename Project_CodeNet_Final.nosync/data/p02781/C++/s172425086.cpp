#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <string>

#define rep(i, a, b) for ( int i = (a); i < (b); i++ )
#define per(i, a, b) for ( int i = (b)-1; i >= (a); i--)
#define pb push_back
#define mp make_pair
#define bg begin()
#define en end()


using namespace std;

typedef long long ll;

static const long long MOD = 1000000007;

int ans;
string s;
int K;
ll dp[105][4][2];

int main(void) {
    cin >> s;
    scanf("%d", &K);
    int n = (int)s.size();


    ll x = s[0] - '0'; 
    dp[0][1][0] = 1; //未満フラグ0のとき、先頭の出現数1が先頭の数字そのもの１つ
    if (x > 1) dp[0][1][1] = x-1; //未満フラグ1では、出現数1が1〜x-1通り
    dp[0][0][1] =1; //未満フラグ1の出現数0は確実に1通り。先頭が1未満はありえない。

    rep(i, 1, n) {
        ll d = s[i] - '0';
        dp[i][0][1] = 1; //未満フラグ1でかつ、出現数0はi桁目まで全て0を採用したときの1通り
        rep(j, 1, 4) {
          
          /* --- 0→0の遷移 --- 
          桁の数字はNのi桁目に忠実　*/
            if (d > 0) { // i桁目が0でないとき
                dp[i][j][0] = dp[i-1][j-1][0]; //出現数は1増える
            } else {
                dp[i][j][0] = dp[i-1][j][0]; //出現数に変化なし
            }
            
            /* --- 1→1の遷移 --- 
             桁の数字はなんでもよい */
          
           //1桁前の出現数が、現在の出現数-1のものに対し、1〜9までの組み合わせが発生する
          dp[i][j][1] += dp[i-1][j-1][1] * 9;
          
          // 0のときは、i-1桁目から出現数が変化しない
          dp[i][j][1] += dp[i-1][j][1];
            
            
            /* ---  0→1の遷移 --- 
            Nのi桁目の数字未満となる必要がある
            */
            if (d > 0) { // 0より大きいときしか更新が発生しない
            // i-1桁目の出現数が、現在の出現数-1のものに関して、1〜d-1までの組み合わせが発生する
                dp[i][j][1] += dp[i-1][j-1][0] * (d-1) ;
                
                // 0のとき、同じ出現数のまま引き継ぐ
                dp[i][j][1] += dp[i-1][j][0];
                
            }
        }
    }

    printf("%lld\n", dp[n-1][K][0]+dp[n-1][K][1]);

    return 0;
}

