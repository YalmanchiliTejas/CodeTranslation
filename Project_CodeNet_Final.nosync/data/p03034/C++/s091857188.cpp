#include <bits/stdc++.h>
#define err(args...) {}
#ifdef DEBUG
#include "_debug.cpp"
#endif
using namespace std;
using ll = long long;
using ld = long double;
template <typename T> using lim = numeric_limits<T>;
template <typename T> istream& operator>>(istream& is, vector<T>& a) { for(T& x : a) { is >> x; } return is; }
template <typename X, typename Y> istream& operator>>(istream& is, pair<X, Y>& p) { return is >> p.first >> p.second; }
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    ll rt_n = int(sqrt(n));
    vector<ll> s(n);
    cin >> s;
    vector<vector<vector<ll>>> modsum(rt_n);
    for(int c = 1; c < rt_n; c++) {
        modsum[c] = vector<vector<ll>>(c);
        for(int i = 0; i < n; i++) {
            modsum[c][i % c].push_back(s[i]);
        }
        for(int j = 0; j < c; j++) {
            partial_sum(modsum[c][j].begin(), modsum[c][j].end(), modsum[c][j].begin());
        }
    }
    auto rsq = [](vector<ll>& p, int L, int R) {
        return p[R - 1] - (L ? p[L - 1] : 0);
    };
    ll ans = 0;
    for(ll c = 1; c <= n; c++) {
        for(ll a = (n - 1) % c; a < n - 1; a += c) {
            ll b = a - c;
            if(b > 0 and b < a and (a % c != 0 or a + c * (a / gcd(a, b) - 1) >= n - 1)) {
                ll cur = 0;
                if(c >= rt_n) {
                    for(int i = a, step = 0; i < n and step < (n - 1 - a) / c; i += c, step++) {
                        cur += s[i];
                    }
                    for(int i = a - b, step = 0; i < n and step < (n - 1 - a) / c; i += c, step++) {
                        cur += s[i];
                    }
                } else {
                    int L1 = a / c, L2 = (a - b) / c;
                    cur += rsq(modsum[c][a % c], L1, L1 + (n - 1 - a) / c);
                    cur += rsq(modsum[c][(a - b) % c], (a - b) / c, L2 + (n - 1 - a) / c);
                }
                ans = max(ans, cur);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
