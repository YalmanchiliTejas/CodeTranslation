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
        if (e&1) {
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
    r = min(r, n-r);
    ll ans = 1;
    for (ll i = 1; i <= r; ++i) {
        ans = (ans * (n-i+1))/(i); 
    }
    return ans;
}

ll nCr(tuple<ll,ll> t) {
    auto n = get<0>(t);
    auto k = get<1>(t);
    return nCr(n+k-1, k);
}

template<typename T>
void print(const T &v) {
    cout << v << " ";
}

template<typename T>
void print(const vector<T> &v) {
    for (auto &i : v) {
        print(i);
    }
    cout << endl;
}

struct myHash {
    size_t operator()(const pair<ll,ll> &p) const {
        return p.first + p.second;
    }
};

unordered_map<pair<ll,ll>, ll, myHash> m;

ll dp(ll i, ll j, vector<ll> &A) {
    if (m.find({i, j}) != m.end()) {
        return m[{i, j}];
    }

    if (i == 0 && j == 0) {
        ll temp = A[0];
        m[{i, j}] = temp;
        return temp;
    } else if (j == 0) {
        ll temp = max(A[i], dp(i-1, j, A));
        m[{i, j}] = temp;
        return temp;
    } else if (j > i/2) {
        return LLONG_MIN;
    } else {
        ll temp = max(A[i] + dp(i-2, j-1, A), dp(i-1, j, A));
        m[{i, j}] = temp;
        return temp;
    }
}

void solve() {
    ll n;
    cin >> n;

    vector<ll> A(n);
    for (auto &i : A) {
        cin >> i;
    }

    ll num = n/2;
    cout << dp(n-1,num-1,A);
    /**
     * 
     * n elements with n/2 positions to fill
     * consider i'th element for j'th position
     * max sum with i-2'th element with j-1'th position or max i-1th as j'th
     * 
     * 1'st element cannot be at n/2 position
     * only at 1 or not
     * 
     * i/2'th position at max
     */ 
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