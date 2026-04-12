#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define F first
#define S second
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define pb push_back
#define fastIO ios::sync_with_stdio(0), cin.tie(0)
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void debug_out() {
    cerr << endl;
}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H), debug_out(T...);
}
const ll m = 1e9 + 7;
ll mulmod(ll a, ll b, ll m) {
    ll r = a * b - (ll)((long double)a * b / m + .5) * m;
    return r < 0 ? r + m : r;
}
int main() {
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
#define debug(...) 3
    fastIO;
#endif
    int n;
    cin >> n;
    vector<ll> v(n), pre(n);
    forn(i, n)cin >> v[i];
    sort(all(v));
    pre[0] = v[0];
    for(int i = 1; i < n; i++)pre[i] = (pre[i - 1] % m + v[i] % m) % m;
    ll ans = 0;
    for(int i = 0; i < n - 1; i++) {
        ans = (ans % m + mulmod(v[i], (pre[n - 1] - pre[i] + m) % m,m) % m) % m;
    }
    cout << ans << endl;
    return 0;
}
