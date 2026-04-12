// 解き直し.
// ABC 128解説.
// https://img.atcoder.jp/abc128/editorial.pdf
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
LL S[123321];

int main() {
    
    // 1. 入力情報取得.
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) scanf("%lld", S + i);
    
    // 2. 解説通り.
    // 以下の情報から, 計算するとのこと.
    // 0, (N - 1) - k * C, C, (N - 1) - (k - 1) * C, 2 * C, ... k * C, N - 1.
    // -> f(k + 1, C) = f(k, C) + S[N - 1 - k * C] + S[k * C] (k >= 0)
    LL ans = 0;
    for(int c = 1; c < N; c++){
        LL cur = 0, bef = 0;
        map<LL, int> route; // 経路情報を保存.
        for(int k = 0; k < (N - 1) / c; k++){
            
            // 2-1. 経路情報チェック.
            // すでに通っていた場合は, 終了.
            int pos1 = N - 1 - k * c;
            int pos2 = k * c;
            route[pos1]++, route[pos2]++;
            if(route[pos1] != 1 || route[pos2] != 1) break;
            
            // 2-2. cur更新.
            cur = bef + S[pos1] + S[pos2];
            
            // 2-3. 最終得点更新.
            ans = max(ans, cur);
            
            // 2-4. bef更新.
            bef = cur;
        }
    }
    
    // 3. 出力 ～ 後処理.
    printf("%lld\n", ans);
    return 0;
    
}