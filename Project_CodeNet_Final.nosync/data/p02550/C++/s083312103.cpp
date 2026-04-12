#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using vb = vector<bool>;
using P = pair<ll, ll>;
template <typename T> using pq = priority_queue<T>;
template <typename T> using minpq = priority_queue<T, vector<T>, greater<T>>;
template <typename T, typename K> using ump = unordered_map<T, K>;
const ll dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll e5 = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for (ll i = ll(n - 1); i >= 0; i--)
#define each(i, mp) for (auto &i : mp)
#define eb emplace_back
#define F first
#define S second
#define all(obj) (obj).begin(), (obj).end()

template <class T> ostream &operator<<(ostream &out, const vector<T> &list) {
    ll n = list.size();
    rep(i, n) out << list[i] << ' ';
    return out;
}

template <class T> istream &operator>>(istream &in, vector<T> &list) {
    ll n = list.size();
    rep(i, n) in >> list[i];
    return in;
}

template <class T> ostream &operator<<(ostream &out, const vector<vector<T>> &list) {
    ll n = list.size();
    rep(i, n) out << list[i] << '\n';
    return out;
}

/* ------------- ANSWER ------------- */
/* ---------------------------------- */
template <std::uint_fast64_t Modulus> class modint {
    using u64 = std::uint_fast64_t;

public:
    u64 x;

    constexpr modint(const u64 x = 0) noexcept : x(x % Modulus) {}

    constexpr u64 &value() noexcept { return x; }

    constexpr const u64 &value() const noexcept { return x; }

    constexpr modint operator+(const modint rhs) const noexcept { return modint(*this) += rhs; }

    constexpr modint operator-(const modint rhs) const noexcept { return modint(*this) -= rhs; }

    constexpr modint operator*(const modint rhs) const noexcept { return modint(*this) *= rhs; }

    constexpr modint operator/(const modint rhs) const noexcept { return modint(*this) /= rhs; }

    constexpr modint &operator+=(const modint rhs) noexcept {
        x += rhs.x;
        if (x >= Modulus) {
            x -= Modulus;
        }
        return *this;
    }

    constexpr modint &operator-=(const modint rhs) noexcept {
        if (x < rhs.x) {
            x += Modulus;
        }
        x -= rhs.x;
        return *this;
    }

    constexpr modint &operator*=(const modint rhs) noexcept {
        x = x * rhs.x % Modulus;
        return *this;
    }

    constexpr modint &operator/=(modint rhs) noexcept {
        u64 exp = Modulus - 2;
        while (exp) {
            if (exp % 2) {
                *this *= rhs;
            }
            rhs *= rhs;
            exp /= 2;
        }
        return *this;
    }
};

typedef vector<modint<mod>> vmod;
typedef vector<vmod> vvmod;

void solve() {
    ll n;
    ll x, m;
    cin >> n >> x >> m;
    ll now = x;
    ll sum = x;
    set<ll> cnts{x};
    ump<ll, ll> numToIdx;
    map<ll, ll> numToSum;
    numToIdx[x] = 0;
    numToSum[0] = x;
    for (ll i = 2; i <= n; ++i) {
        now = (now * now) % m;
        if (cnts.find(now) == cnts.end()) {
            cnts.insert(now);
            numToIdx[now] = i - 1;
            sum += now;
            numToSum[i - 1] = sum;
        } else {
            ll interval = i - 1 - numToIdx[now];
            sum += now;
            sum += (numToSum.rbegin()->second - numToSum[numToIdx[now] - 1]) * ((n - i) / interval);
            for (ll j = ((n - i) / interval) * interval + i; j <= n - 1; ++j) {
                now = (now * now) % m;
                sum += now;
            }
            break;
        }
    }
    cout << sum << '\n';
}

int main() {
#ifdef MY_DEBUG
    while (true) {
#endif
        solve();
#ifdef MY_DEBUG
    }
#endif
    return 0;
}
