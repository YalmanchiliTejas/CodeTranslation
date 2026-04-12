// 解き直し.
// https://atcoder.jp/contests/abc179/editorial/115
// C++(GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) repex(i, a, b, 1)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)
#define pb push_back
LL a[101010]; // 数列を保存.

int main(){
    
    // 1. 入力情報.
    LL N, X, M;
    scanf("%lld %lld %lld", &N, &X, &M);
    
    // 2. 数列を計算(繰り返しを確認するまで).
    set<LL> s;
    LL cur = X;
    int idx = 0;
    rep(i, 101010){
        // 繰り返しかを判定.
        if(!s.count(cur)){
            a[i] = cur;
            s.insert(cur);
            idx = i;
        }else{
            break;
        }
        
        // 次項計算.
        cur *= cur;
        cur %= M;
    }
    
    // 3. 数列を分割.
    LL bSum = 0, cSum = 0; // 合計.
    vector<LL> b; // 繰り返し始まるまで.
    vector<LL> c; // 繰り返し部分.
    bool f = false; // 繰り返し部分開始フラグ.
    rep(i, idx + 1){
        if(cur == a[i]) f = true;
        if(f) c.pb(a[i]), cSum += a[i];
        else  b.pb(a[i]), bSum += a[i];
    }
    
    // 4. N項目までの和を計算.
    LL ans = 0, bl = (LL)b.size(), cl = (LL)c.size();
    if(N <= bl + cl){
        rep(i, (int)N) ans += a[i];
    }else{
        LL q = (N - bl) / cl, r = (N - bl) % cl;
        ans += bSum;
        ans += cSum * q;
        rep(i, (int)r) ans += c[i];
    }
    
    // 5. 出力.
    printf("%lld\n", ans);
    return 0;
    
}