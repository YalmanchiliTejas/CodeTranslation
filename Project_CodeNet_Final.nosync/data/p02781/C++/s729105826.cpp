#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5+ 5;
ll arr[maxn];
ll C(ll n, ll m) {
    ll res = 1;
    for (ll i = n; i > n - m; --i)
        res *= i;
    for (ll i = 2; i <= m; ++i)
        res /= i;
    return res;
}
ll bf(string &t, string &s, int k) {
    if (t > s) return 0;
    if (!k) return t <= s;
    if (t.length() == s.length()) return t <= s && k == 0;
    ll res = 0;
    for (int i = 0; i <= 9; ++i) {
        t.push_back('0' + i);
        res += bf(t, s, (i? k - 1: k));
        t.pop_back();
    }
    return res;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s;
    int k; cin >> k;
    ll ans = 0;
    for (int i = k; i < s.length(); ++i)
        ans += pow(9, k) * C(i - 1, k - 1);
    for (int i = 1; i <= 9; ++i) {
        string t = string(1, '0' + i);
        ans += bf(t, s, k - 1);
    }
    cout << ans << '\n';
    return 0;
}