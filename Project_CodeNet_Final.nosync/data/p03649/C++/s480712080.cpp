// 解き直し.
// https://img.atcoder.jp/arc079/editorial.pdf
// C++(GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) repex(i, a, b, 1)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)
LL a[55];

int main(){
    
    // 1. 入力情報.
    int N;
    scanf("%d", &N);
    rep(i, N) scanf("%lld", &a[i]);
    
    // 2. 操作回数をカウント.
    LL ans = 0;
    function<void()> f = [&](){
        // 終了条件.
        bool ok = true;
        rep(i, N){
            if(a[i] >= N){
                ok = false;
                break;
            }
        }
        if(ok) return;
        
        // 今回の操作回数を計算.
        LL cur = 0;
        rep(i, N) cur += a[i] / (LL)N;
        
        // 数列の各要素を更新.
        rep(i, N){
            LL b = a[i] / (LL)N;
            a[i] -= b * (LL)N;
            a[i] += cur - b;
        }
        
        // 今回の操作回数を加算.
        ans += cur;
        
        // 次回の操作.
        f();
    };
    f();
    
    // 3. 出力.
    printf("%lld\n", ans);
    return 0;
    
}