#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
constexpr ll M = 1e9 + 7;
inline ll sum_1(const ll n) { return ((n * (n + 1)) / 2) % M; }
inline ll sum_2(const ll n) { return ((n * (n + 1) * (2 * n + 1)) / 6) % M; }
inline ll sum_3(const ll n) { return (((n * (n + 1)) / 2) % M * ((n * (n + 1)) / 2) % M) % M; }
inline ll sum_1(const ll i, const ll j) { return (sum_1(j) - sum_1(i - 1) + M) % M; }
inline ll sum_2(const ll i, const ll j) { return (sum_2(j) - sum_2(i - 1) + M) % M; }
inline ll sum_3(const ll i, const ll j) { return (sum_3(j) - sum_3(i - 1) + M) % M; }

ll pow_f(ll b, ll e) {
    ll ans = 1;
    b = b % M;
    while (e) {
        if (e & 1) {
            ans = (ans * b) % M;
        }
        b = (b * b) % M;
        e >>= 1;
    }
    return ans;
}

ll nCr(ll n, ll r) {
    if (r > n || n < 0 || r < 0) { return 0; }
    if (n == r || r == 0) { return 1; }
    r = min(r, n - r);
    ll ans = 1;
    for (ll i = 1; i <= r; ++i) {
        ans = (ans * (n - i + 1)) / (i);
    }
    return ans;
}

ll nCr(tuple<ll, ll> t) {
    auto n = get<0>(t);
    auto k = get<1>(t);
    return nCr(n + k - 1, k);
}

template <typename T>
void print(const T &v) {
    cout << v << " ";
}

template <typename T>
void print(const vector<T> &v) {
    for (auto &i : v) {
        print(i);
    }
    cout << endl;
}

map<pair<ll, ll>, ll> m;

ll dp(ll i, ll j, vector<ll> &A) {
    if (m.find({i, j}) != m.end()) {
        return m[{i, j}];
    }
    if (i < 0 || j < 0) {
        return LLONG_MIN;
    }
    if (j <= i / 2) {
        if (i == 0 && j == 0) {
            return A[0];
        } else if (i >= 1 && j == 0) {
            ll temp = max(A[i], dp(i - 1, j, A));
            m[{i, j}] = temp;
            return temp;
        }

        ll temp = max(A[i] + dp(i - 2, j - 1, A), dp(i - 1, j, A));
        m[{i, j}] = temp;
        return temp;
    } else {
        return LLONG_MIN;
    }
}

void solve() {
    ll n;
    cin >> n;

    vector<ll> A(n);
    for (auto &i : A) {
        cin >> i;
    }

    ll num = n / 2;

    cout << dp(n - 1, num - 1, A) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifdef D_LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif

    solve();

    return 0;
}