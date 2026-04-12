// 記述をスリム化して, 再提出.
// 解き直し.
// https://img.atcoder.jp/abc162/editorial.pdf
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) repex(i, a, b, 1)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)
LL a[202020], dp[5][202020];

int main(){
    
    // 1. 入力情報.
    int N;
    scanf("%d", &N);
    rep(i, N) scanf("%lld", &a[i]);
    
    // 2. 解説通り(dp更新).
    dp[1][1] = a[0];
    dp[2][1] = max(a[0], a[1]);
    if(N >= 3){
        dp[3][1] = max({a[0], a[1], a[2]});
        dp[3][2] = a[0] + a[2];
    }
    repx(i, 4, N + 1){
        // i に ついて, s個以上, e個以下 を 選択.
        int s = i / 2 - 1, e = (i + 1) / 2;
        int c = (i % 3 == 0) ? 3 : (i % 3); // 現在.
        int o = (c - 1 == 0) ? 3 : c - 1;   // 一つ前.
        int t = (o - 1 == 0) ? 3 : o - 1;   // 二つ前.
        dp[c][s]     = max(dp[t][s - 1] + a[i - 1], dp[o][s]);
        dp[c][s + 1] = max(dp[t][s] + a[i - 1],     dp[o][s + 1]);
        if(s + 2 == e) dp[c][s + 2] = dp[t][s + 1] + a[i - 1];
    }
    // rep(i, 5){
    //     rep(j, N + 1) printf("%lld ", dp[i][j]);
    //     puts("");
    // }
    
    // 3. 出力.
    int index = (N % 3 == 0) ? 3 : (N % 3);
    printf("%lld\n", dp[index][N / 2]);
    return 0;
    
}