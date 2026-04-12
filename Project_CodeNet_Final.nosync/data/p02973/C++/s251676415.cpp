// 解き直し.
// ABC 134解説.
// https://img.atcoder.jp/abc134/editorial.pdf
#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
    
    // 1. 入力情報取得.
    int N;
    scanf("%d", &N);
    vector<LL> A(N);
    vector<LL> dp;
    // 解説通りだが, LIS使う必要があるため, 後ろ側から値を保存.
    for(int i = 0; i < N; i++) scanf("%lld", &A[N - i - 1]);
    // for(int i = 0; i < N; i++) printf("%lld ", A[i]);
    
    // 2. 解説通り.
    // -> LIS で 解く必要があるとのこと.
    // -> "広義"単調減少列 との 記載から, lower_bound を upper_bound に 変更.
    dp.push_back(A[0]);
    for(int i = 1; i < N; i++){
        // 2-1. dpテーブル末尾 の 要素(last)以上 の 値(A[i])であれば, dpテーブル に 追加.
        int last = dp.back();
        // if(last < A[i]) dp.push_back(A[i]);
        if(last <= A[i]) dp.push_back(A[i]);    // "広義"用.
        // 2-2. dpテーブル末尾 の 要素(last) より小さな値(A[i])であれば, 
        // dpテーブル上 の 更新場所 を 探索後, dpテーブル を 更新.
        if(last > A[i]){
            // auto it = lower_bound(dp.begin(), dp.end(), A[i]);
            auto it = upper_bound(dp.begin(), dp.end(), A[i]);    // "広義"用.
            int dist = it - dp.begin();
            dp[dist] = A[i];
            // for(int i = 0; i < dp.size(); i++) cout << dp[i] << " ";
            // cout << endl;
        }
    }
    // for(int i = 0; i < dp.size(); i++) cout << dp[i] << " ";
    // cout << endl;
    
    // 3. 出力 ～ 後処理.
    printf("%d\n", dp.size());
    return 0;
    
}