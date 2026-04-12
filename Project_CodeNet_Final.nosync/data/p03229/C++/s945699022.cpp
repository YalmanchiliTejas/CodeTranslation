#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define repx(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)
#define pb push_back
#define pf push_front
LL A[101010];

int main(){
    
    // 1. 入力情報.
    int N;
    scanf("%d", &N);
    rep(i, N) scanf("%lld", &A[i]);
    
    // 2. sort.
    sort(A, A + N);
    
    // 3. ぐるぐるする.
    deque<LL> dq;
    rep(i, N / 2){
        // 奇数ならば, 後ろに追加, 偶数ならば, 前に追加.
        if(i % 2) dq.pb(A[i]), dq.pf(A[N - 1 - i]);
        else      dq.pf(A[i]), dq.pb(A[N - 1 - i]);
    }
    // if(N & 1) dq.pf(A[N / 2]);
    // 
    // ex.
    // 5
    // 1
    // 19
    // 2
    // 6
    // 7
    // -> 6 は 前(6 7 1 19 2)でなく, 後ろ(7 1 19 2 6)に追加した方が, 大きくなる(42 < 45).
    if(N & 1){
        if(abs(dq.front() - A[N / 2]) > abs(dq.back() - A[N / 2])) dq.pf(A[N / 2]);
        else                                                       dq.pb(A[N / 2]);
    }
    // for(auto &p : dq) printf("%lld ", p);
    // puts("");
    
    // 4. 隣り合う要素の差の合計.
    LL ans = 0;
    rep(i, N - 1) ans += abs(dq[i + 1] - dq[i]);
    
    // 5. 出力.
    printf("%lld\n", ans);
    return 0;
    
}