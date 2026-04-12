// 以下のソースを勉強する.
// zscoder氏.
// https://atcoder.jp/contests/dp/submissions/3941257
#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int dp[11111][111][2];
const int MOD = (1e9 + 7);

int add(int a, int b){
    a += b;
    while(a >= MOD) a -= MOD;
    return a;
}

int main(){
    
    // 1. 入力情報取得.
    char C[11111];
    scanf("%s", C);
    string K(C);
    K = "0" + K;
    int D;
    scanf("%d", &D);
    
    // 2. dp更新.
    int N = K.length();
    dp[0][0][0] = 1;
    for(int i = 0; i + 1 < N; i++){
        for(int j = 0; j < D; j++){
            for(int k = 0; k < 2; k++){
                int v = dp[i][j][k];
                if(v == 0) continue;
                for(int dig = 0; dig < 10; dig++){
                    if(!k && (dig > K[i + 1] - '0')) continue;
                    int newk = k;
                    if(!k && (dig < K[i + 1] - '0')) newk = 1;
                    dp[i + 1][(j + dig) % D][newk] = add(dp[i + 1][(j + dig) % D][newk], v);
                }
            }
        }
    }
    int ans = MOD - 1;
    for(int k = 0; k < 2; k++) ans = add(ans, dp[N - 1][0][k]);
    
    // 3. 出力.
    printf("%lld\n", ans);
    return 0;
}