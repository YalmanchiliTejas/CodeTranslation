// ※※※ 解答不能 ※※※
// scott_wu氏
// https://atcoder.jp/contests/agc040/submissions/8281419
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const LL MOD = 998244353;
const int MAXN = 1.1e7;

LL fac[MAXN];
LL finv[MAXN];

LL cpow(LL b, int e){
    if(e == 0) return 1;
    LL v = cpow(b, e / 2);
    v = (v * v) % MOD;
    if(e % 2) v = (v * b) % MOD;
    return v;
}

int main(){
    int N;
    scanf("%d", &N);
    fac[0] = 1;
    for(int i = 1; i <= N; i++) fac[i] = (fac[i - 1] * i) % MOD;
    finv[N] = cpow(fac[N], MOD - 2);
    for(int i = N - 1; i >= 0; i--) finv[i] = (finv[i + 1] * (i + 1)) % MOD;
    LL p2 = 1;
    LL ans = 0;
    for(int i = 0; i < N / 2; i++){
        // N choose i * 2 ^ i
        LL nadd = (fac[N] * ((finv[i] * finv[N - i]) % MOD)) % MOD;
        ans = (ans + (nadd * p2)) % MOD;
        p2 = (2 * p2) % MOD;
    }
    ans = (2 * ans) % MOD;
    LL p3 = 1;
    for(int i = 0; i < N; i++) p3 = (3 * p3) % MOD;
    ans = (p3 - ans + MOD) % MOD;
    printf("%lld\n", ans);
    return 0;
}