#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll MOD = 1e9 + 7;

ll lgput(ll b, int p) {
    ll ans = 1;
    while(p) {
        if(p % 2)
          ans = (ans * b) % MOD;
        b = (b * b) % MOD;
        p /= 2;
    }
    return ans;
}

ll invmod(ll x) {
    return lgput(x, MOD - 2);
}

int main() {

    ios::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> fact(n * m + 1, 1);
    for(int i = 1; i <= n * m; i ++)
      fact[i] = (i * fact[i - 1]) % MOD;
    ll comb = (((fact[n * m - 2] * invmod(fact[k - 2])) % MOD) * invmod(fact[n * m - k])) % MOD;

    ll s = 0;
    for(int i = -(n - 1); i <= n - 1; i ++)
      for(int j = -(m - 1); j <= m - 1; j ++) {
        s = (s + (1LL * (abs(i) + abs(j)) * (n - abs(i)) * (m - abs(j))) % MOD) % MOD;
        //cout << i << " " << j << " -> " << s << endl;
       }
    s = (s * comb) % MOD;
    cout << (s * invmod(2)) % MOD;
    return 0;
}
