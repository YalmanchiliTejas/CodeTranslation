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
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n), add(n);
    cin >> a;
    ll ans = 0;
    while(any_of(a.begin(), a.end(), [&](ll x) { return x >= n; })) {
        for(int i = 0; i < n; i++) {
            add[i] = a[i] / n;
            a[i] %= n;
        }
        ll s = accumulate(add.begin(), add.end(), 0ll);
        for(int i = 0; i < n; i++) {
            a[i] += s - add[i];
        }
        ans += s;
    }
    cout << ans << endl;
    return 0;
}
