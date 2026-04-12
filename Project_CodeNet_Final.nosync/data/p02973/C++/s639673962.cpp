// ※※※ 上級者の解答を勉強する. ※※※
// ats5515氏.
// https://atcoder.jp/contests/abc134/submissions/6459574
#include <bits/stdc++.h>
#define int long long
using namespace std;
int INF = (int)1 << 62;

// 広義単調増加列の長さを返却.
// @param a: 整数配列.
// @return: 広義単調増加列の長さ.
int LIS(vector<int> &a){
    int N = a.size();
    vector<int> dp(N, INF);
    for(int i = 0; i < N; ++i) *upper_bound(dp.begin(), dp.begin() + N, a[i]) = a[i];
    return lower_bound(dp.begin(), dp.begin() + N, INF) - dp.begin();
}

signed main(){
    
    // 1. 入力情報取得.
    int N;
    scanf("%d", &N);
    vector<int> A(N);
    for(int i = 0; i < N; i++) scanf("%d", &A[i]);
    reverse(A.begin(), A.end());

    // 2. 出力 ～ 後処理.
    printf("%d\n", LIS(A));
    return 0;
    
}