#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = (int)(n - 1); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const int INF = 1e9;
const ll MOD = 1e9 + 7;
const ll LINF = 1e18;
template <class T>
void get_unique(vector<T>& x) {
    x.erase(unique(x.begin(), x.end()), x.end());
}
template <class T>
bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T& a, const T& b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
vector<T> make_vec(size_t a) {
    return vector<T>(a);
}
template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
template <typename T>
ostream& operator<<(ostream& os, vector<T> v) {
    for (int i = 0; i < sz(v); i++) {
        os << v[i];
        if (i < sz(v) - 1) os << " ";
    }
    return os;
}
int main() {
    ll n, x, m;
    cin >> n >> x >> m;
    set<ll> st;
    st.insert(x);
    vector<ll> a = {x};
    ll b = -1;
    while (1) {
        ll nxt = a.back() * a.back() % m;
        if (st.count(nxt)) {
            rep(i, sz(a)) if (a[i] == nxt) b = i;
            break;
        }
        st.insert(nxt);
        a.push_back(nxt);
    }
    if (sz(a) >= n) {
        cout << accumulate(a.begin(), a.begin() + n, 0ll) << '\n';
        return 0;
    }
    ll ans = 0;
    ans += accumulate(a.begin(), a.begin() + b, 0ll);
    n -= b;
    ans += accumulate(a.begin() + b, a.end(), 0ll) * (n / ll(sz(a) - b));
    ans += accumulate(a.begin() + b, a.begin() + b + (n % ll(sz(a) - b)), 0ll);
    cout << ans << '\n';
}