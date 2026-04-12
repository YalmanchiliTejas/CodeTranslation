#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;


string N;
int K, n;
ll ans;
vector<int> p9;


void input() {
    cin >> N >> K;
}


const int MOD = 1e9 + 7;
const int MAX = 100;
ll fac[MAX], finv[MAX], inv[MAX];


void comb_init() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}


ll comb(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}


ll solve(int i, int j) {
    if (n - i < j) return 0;
    if (j == 0) return 1;
    ll x = 0;
    if (N[i] == '0') x += solve(i+1, j);
    else {
        x += p9[j] * comb(n - i - 1, j);
        x += (N[i] - '1') * p9[j-1] * comb(n - i - 1, j - 1);
        x += solve(i + 1, j - 1);
    }
    return x;
}


int main() {
    comb_init();
    input();
    p9 = vector<int>(4);
    p9[0] = 1;
    rep(i, 3) p9[i+1] = p9[i] * 9;
    n = N.size();
    vector<vector<ll>> dp(n, vector<ll>(K+1, 0));
    ans = 0;
    for (int i = 1; i < n; i++) {
        ans += p9[K] * comb(i - 1, K - 1);
    }
    ans += (N[0] - '1') * p9[K-1] * comb(n - 1, K - 1);
    ans += solve(1, K - 1);
    cout << ans << endl;
}
