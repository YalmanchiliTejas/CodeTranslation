#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll INF = 1000000000000000000;
const ll mod = 1000000007;
const ll MAX = 510000;

ll fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = mod - inv[mod % i] * (mod / i) % mod;
        finv[i] = finv[i - 1] * inv[i] % mod;
    }
}

// 二項係数計算
ll COM(ll n, ll k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}
signed main() {
    ll k, not0 = 0; string s; cin >> s >> k; COMinit();
    if (k == 1) {
        cout << (ll)(s[0] - '0') + 9 * (s.size() - 1) << endl;
    }
    for (int h = 1; h < s.size(); h++) {
        if ((s[h] - '0') != 0) { not0 = h; break; }
    }
    if (k == 2) {
        ll x = 9 * 9 * COM(s.size() - 1, 2);//最初入れない
        ll y = ((ll)(s[0] - '0') - 1) * 9 * (s.size() - 1);//最初入れる（NO最高)
        if (not0 == 0) { cout << x + y << endl; return 0; }
        cout << x + y + (ll)(s[not0] - '0') + 9 * (s.size() - not0 - 1) << endl;
    }

    if (k == 3) {
        ll x = 9 * 9 * 9 * COM(s.size() - 1, 3);//最初入れない
        x += ((ll)(s[0] - '0') - 1) * 9 * 9 * COM(s.size() - 1, 2);//最初入れる（NO最高)
        if (not0 == 0) { cout << x << endl; return 0; }
        x += ((s[not0] - '0') - 1) * 9 * (s.size() - not0 - 1);//not0含める(NO最高)
        x += 9 * 9 * COM(s.size() - not0 - 1, 2);//not0含めない
        ll z = 0;
        for (int h = not0 + 1; h < s.size(); h++) {
            if ((s[h] - '0') != 0) { not0 = h; z++; break; }
        }
        if (z == 0) { cout << x << endl; return 0; }
        x += (ll)(s[not0] - '0') + 9 * (s.size() - not0 - 1);
        cout << x << endl;
    }
	return 0;
}