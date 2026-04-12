#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;
using ll = long long int;

const int MAXN = 4000;
const ll MOD = 1000000007;
ll C[MAXN+10][MAXN+10], inv[MAXN+10];
map< pair<ll, ll>, ll > rec;

ll mod_pow(ll n, ll k) {
    ll res = 1; n %= MOD;
    for(; k>0; k>>=1) {
        if(k & 1) (res *= n) %= MOD;
        (n *= n) %= MOD;
    }
    return res;
}

void init() {
    for(int i=0; i<=MAXN; i++) {
        inv[i] = mod_pow(i, MOD-2);
        C[i][0] = 1;
        for(int j=1; j<=i; j++) {
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
        }
    }
}

ll nCr(ll n, ll r) {
    if(r < 0 or n < r) return 0;
    if(r > n - r) return nCr(n, n-r);
    if(n <= MAXN and r <= MAXN) return C[n][r];
    if(rec.count(make_pair(n, r))) return rec[make_pair(n, r)];
    
    ll res = 1;
    for(int i=0; i<r; i++) {
        (res *= (n - i) % MOD) %= MOD;
        (res *= inv[i + 1]) %= MOD;
    }
    return rec[make_pair(n, r)] = res;
}

ll nHr(ll n, ll r) {
    if(n == 0 and r == 0) return 1;
    return nCr(n+r-1, r);
}

int solve_testcase() {
    ll N, D, X; cin >> N >> D >> X;
    if(N == 0) return 1;
    rec.clear();
    
    ll Y = min(N, D), ans = 0;

    // 制約違反が i 日ある
    for(int i=0; i<=Y; i++) {
        // 0 個でないところが j 日ある
        for(int j=i; j<=Y; j++) {
            // 1 個以上いれるのが (j-i) 個
            // X 個以上いれるのが i 個
            ll rem = N - i*X - (j-i);
            if(rem < 0) continue;

            // 1 個以上・X 個以上の並び
            ll add = nCr(j, i);

            // j 日に rem 個すきにいれていい
            // j も rem も小さいのでこれは O(1)
            (add *= nHr(j, rem)) %= MOD;

            // 残り D - j 日は 0 にする (毎回計算すると破滅しそう)
            (add *= nHr(j+1, D-j)) %= MOD;

            if(i % 2) (ans -= add) %= MOD;
            else (ans += add) %= MOD;
            if(ans < 0) ans += MOD;
        }
    }
    cout << ans << endl;
    return 0;
}

int main() {
    init();
    while(!solve_testcase());
    return 0;
}

