// 以下のソースを勉強する.
// zscoder氏.
// https://atcoder.jp/contests/dp/submissions/3939565
#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL a[3333];
LL dp[3333][3333];

// 太郎君から見て, X - Y が 最大となるように要素を選択.
// ※ 次郎君の得点 Y は, recursive(l + 1, r) or recursive(l, r - 1) で 計算されたものと見ている.
// @param l: 先頭要素の場所.
// @param r: 末尾要素の場所.
// @return :
// 先頭要素a[l] or 末尾要素a[r] を 選択した上で, 再帰処理を行う.
LL recursive(int l, int r){
    if(l > r)                 return 0;
    if(l == r)                return a[l];
    if(dp[l][r] != -LL(1e18)) return dp[l][r];
    return (dp[l][r] = max(a[l] - recursive(l + 1, r), a[r] - recursive(l, r - 1)));
}

int main(){
    
    // 1. 入力情報取得.
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) dp[i][j] = -LL(1e18);
    for(int i = 0; i < N; i++) scanf("%d", &a[i]);
    
    // 2. dp更新.
    LL ans = recursive(0, N - 1);
    // for(int i = 0; i < N; ++i){
    //     for(int j = 0; j < N; ++j) printf("%lld ", dp[i][j]);
    //     printf("\n");
    // }
    
    // 3. 出力.
    printf("%lld\n", ans);
    return 0;
}