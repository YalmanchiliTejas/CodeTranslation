// 解き直し.
// https://img.atcoder.jp/abc154/editorial.pdf
#include <bits/stdc++.h>
using namespace std;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) repex(i, a, b, 1)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)
int dp0[111][4]; // 上からi桁目まで決めて, 0でない桁がj個あり, Nより小さいことが確定.
int dp1[111][4]; // 上からi桁目まで決めて, 0でない桁がj個あり, Nより小さいことが未確定.

int main(){
    
    // 1. 入力情報.
    int K;
    char N[111];
    scanf("%s %d", N, &K);
    int d = strlen(N);
    
    // 2. 解説通り.
    // 2-1. dp1更新.
    int c = 1;
    dp1[0][c] = 1; // 1桁目を更新.
    repx(i, 1, d){
        if(N[i] > '0') c++;
        if(c > K)      break; // この条件が無いと, 上手く動作しないように見える.
        dp1[i][min(3, c)] = 1;
    }
    
    // 2-2. dp0更新.
    // 1桁目を更新.
    dp0[0][0] = 1;
    dp0[0][1] = N[0] - '1';
    
    // 2桁目以降を更新.
    repx(i, 1, d) dp0[i][0] = 1;
    repx(i, 1, d){
        repx(j, 1, 4){
            dp0[i][j] = dp0[i - 1][j - 1] * 9;
            dp0[i][j] += dp0[i - 1][j] * 1;
            dp0[i][j] += dp1[i - 1][j - 1] * (N[i] > '1') * (N[i] - '1');
            dp0[i][j] += dp1[i - 1][j] * (N[i] > '0');
        }
    }
    
    // 3. 出力.
    printf("%d\n", dp0[d - 1][K] + dp1[d - 1][K]);
    return 0;
    
}