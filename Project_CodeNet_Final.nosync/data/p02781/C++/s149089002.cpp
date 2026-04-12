#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using Vi = vector<int>;
using Vl = vector<ll>;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

constexpr int I_INF = numeric_limits<int>::max();
constexpr ll L_INF = numeric_limits<ll>::max();

//==================================

ll comb(ll n, ll k) {
    if (n < 0 || k < 0)
        return 0;
    else if (n < k)
        return 0;
    ll res = 1;
    ll d = 1;
    for (int i = 0; i < k; i++) {
        res *= n - i;
        d *= i + 1;
    }
    res /= d;
    return res;
}

ll bpow(ll n, ll k) {
    ll res = 1;
    for (; k > 0; k >>= 1) {
        if (k & 1) res *= n;
        n *= n;
    }
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string S;
    cin >> S;

    int n = (int)S.size();

    int K;
    cin >> K;

    ll ans = 0;
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        int ni = S[i] - '0';
        if (ni == 0) continue;
        ans += comb(n - i - 1, K - cnt) * bpow(9, K - cnt);
        ans += (ni - 1) * comb(n - i - 1, K - 1 - cnt) * bpow(9, K - 1 - cnt);
        ++cnt;
    }

    cnt = 0;
    for (const auto& v : S) {
        if (v != '0') ++cnt;
    }

    if (cnt == K) ++ans;

    cout << ans << endl;

    return 0;
}