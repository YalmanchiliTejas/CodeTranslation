#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
#define yn {puts("Yes");}else{puts("No");}
#define MAX_N 200005

const int MAX = 11000000;
const ll MOD = 998244353;
long long fac[MAX], finv[MAX], inv[MAX];
// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

long long FINV(int n){
    if (n < 0) return 0;
    return finv[n];
}

int main() {
    // 前処理
    COMinit();


    int n; cin >> n;
    ll ans = 1;
    rep(i,n){
        ans *= 3;
        ans %= MOD;
    }

    ll tmp = 0;
    ll two = 2;
    rep(i,n/2){
        tmp += COM(n, i) * two;
        tmp %= MOD;
        two *= 2;
        two %= MOD;
    }

    ans += MOD - tmp;
    ans %= MOD;
    cout << ans << endl;
    return 0;
}
