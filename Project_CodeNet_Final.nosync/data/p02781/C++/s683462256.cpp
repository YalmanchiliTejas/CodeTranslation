#include <iostream>
#include <string>
using namespace std;

typedef long long ll;

// dp[i][j][k] := i 桁目まで見たとき、0 以外の数字がちょうど j 個使われていている数字の個数
// k は、N 未満(:=0)か N と同じ(:=1)かを表すフラグ
ll dp[105][5][2];

int main(){
    string s;   // N を文字列で受け取る
    int K;
    cin >> s >> K;
    int n = s.length();
    
    dp[0][0][1] = 1;    // 0 桁目で、入力 N と一致している個数を 1 とする
    for(int i = 0; i < n; ++i){
        int num = s[i] - '0';   // 入力 N の i+1 桁目の数

        for(int j = 0; j <= K; ++j){
            for(int x = 0; x < 10; ++x){    // i+1 桁目にどの数字を入れる場合を考えるか
                int next = (x == 0) ? 0 : 1;    // j の遷移先を考えるときに必要
                
                // フラグの遷移は、未満 → 未満, 同じ → 未満
                if(x < num){
                    dp[i+1][j+next][0] += dp[i][j][0];
                    dp[i+1][j+next][0] += dp[i][j][1];
                }
                // フラグの遷移は、未満 → 未満, 同じ → 同じ
                else if(x == num){
                    dp[i+1][j+next][0] += dp[i][j][0];
                    dp[i+1][j+next][1] += dp[i][j][1];
                }
                // フラグの遷移は、未満 → 未満
                else{   // x > num
                    dp[i+1][j+next][0] += dp[i][j][0];
                }
            }
        }
    }

    cout << dp[n][K][0] + dp[n][K][1] << endl;
}