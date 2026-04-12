#include <iostream>
#include <string>
#define rep(i, n) for(i = 0; i < n; i++)
using namespace std;

string N;
int K;
int dp[101][2][4] = {0};    //dp[桁数][flag][個数] = 何通り
                    //(桁数, flag, 個数)が状態.
                    
signed main() {
    int i, j, k;
    
    cin >> N >> K;
    int length = N.length();
    
    //length桁の数を上の桁から作る
    //例えばN = 153なら、3桁の数を100の位から作る
    //13とかは013と表現。
    //1つずつ作ってると間に合わないのでDPする.
    
    dp[0][0][0] = 1;
    rep(i, length) {
        rep(j, 2) {
            rep(k, K + 1) {
                //0,1,…,9を試す
                int x;
                rep(x, 10) {
                    if (j == 0 && x > N[i] - '0') { continue; } //Nを超える！
                    int newFlag;
                    if (j == 1) { newFlag = 1; }
                    else if (x < N[i] - '0') { newFlag = 1; }
                    else { newFlag = 0; }
                    
                    int newCnt;
                    if (x != 0) { newCnt = k + 1; }
                    else { newCnt = k; }
                    
                    if (newCnt > K) { continue; }
                    
                    dp[i + 1][newFlag][newCnt] += dp[i][j][k];
                }
            }
        }
    }
    
    int ans = dp[length][1][K];
    
    //ちょうどNの判定が必要！！
    //0以外の桁の個数のカウントをすればよい
    int cnt = 0;
    rep(i, N.length()) {
        if (N[i] != '0') {
            cnt++;
        }
    }
    if (cnt == K) {
        ans += 1;
    }
    
    cout << ans << endl;
    return 0;
}