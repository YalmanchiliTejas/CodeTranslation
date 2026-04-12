#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <functional>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <chrono>
#include <random>

#include <cstring>

using namespace std;

using ll = long long;
ll const MM = 1000000007;

#define pv(val) cerr << #val << '=' << (val) << endl
#define pl cerr << '@' << __LINE__ << endl

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define rep2(i, b, e) for (ll i = (b); i < (e); i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

template <class T>
ostream& operator<<(ostream& os, vector<T> const& vec);
template <class T, size_t S>
ostream& operator<<(ostream& os, array<T, S> const& arr);
template<class T, class U>
ostream& operator<<(ostream& os, pair<T, U> const& p);
template<class... Args>
ostream& operator<<(ostream& os, tuple<Args...> const& t);

template <class T>
ostream& operator<<(ostream& os, vector<T> const& vec) {
    if (vec.empty()) {
        os << "{}";
    } else {
        os << '{';
        for (size_t i = 0; i < vec.size() - 1; i++) os << vec[i] << ", ";
        os << vec.back() << '}';
    }
    return os;
}

template <class T, size_t S>
ostream& operator<<(ostream& os, array<T, S> const& arr) {
    if (arr.empty()) {
        os << "{}";
    } else {
        os << '{';
        for (size_t i = 0; i < arr.size() - 1; i++) os << arr[i] << ", ";
        os << arr.back() << '}';
    }
    return os;
}

template<class T, class U>
ostream& operator<<(ostream& os, pair<T, U> const& p) {
    os << '(' << p.first << ", " << p.second << ')';
    return os;
}

template<size_t I, class... Args>
typename enable_if<sizeof...(Args) == (I + 1)>::type print_tuple(ostream& os, tuple<Args...> const& t) {
    os << get<I>(t);
}
template<size_t I, class... Args>
typename enable_if<sizeof...(Args) != (I + 1)>::type print_tuple(ostream& os, tuple<Args...> const& t) {
    os << get<I>(t) << ", ";
    print_tuple<I + 1, Args...>(os, t);
}

template<class... Args>
ostream& operator<<(ostream& os, tuple<Args...> const& t) {
    os << '(';
    print_tuple<0, Args...>(os, t);
    os << ')';

    return os;
}

struct Timer {
    using Clock = std::chrono::system_clock;
    Clock::time_point startTime;
 
    Timer()
    {
        start();
    }
    void start()
    {
        startTime = Clock::now();
    }
 
    long long milli() const
    {
        return std::chrono::duration_cast<std::chrono::milliseconds>(Clock::now() - startTime).count();
    }
    long long micro() const
    {
        return std::chrono::duration_cast<std::chrono::microseconds>(Clock::now() - startTime).count();
    }
};

namespace math {
    ll gcd(ll u, ll v) {
        while (v != 0) {
            ll r = u % v;
            u = v;
            v = r;
        }
        return u;
    }
    ll lcm(ll m, ll n) {
        if ((0 == m) || (0 == n)) return 0;

        return ((m / math::gcd(m, n)) * n);
    }

    vector<ll> divisors(ll n) {
        vector<ll> ret;
        for (ll i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                ret.push_back(i);
                if (i * i != n) ret.push_back(n / i);
            }
        }
        sort(begin(ret), end(ret));
        return ret;
    }
    set<ll> divisors_set(ll n) {
        set<ll> ret;
        for (ll i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                ret.insert(i);
                if (i * i != n) ret.insert(n / i);
            }
        }
        return ret;
    }

    // https://qiita.com/ofutonfuton/items/92b1a6f4a7775f00b6ae
    struct Combination {
        vector<ll> fac;
        vector<ll> ifac;

        Combination() :
            fac(1000000 + 100),
            ifac(1000000 + 100)
        {
            fac[0] = 1;
            ifac[0] = 1;
            for (ll i = 0; i < 1000000 + 100; i++) {
                fac[i + 1] = fac[i] * (i + 1) % MM;
                ifac[i + 1] = ifac[i] * this->mpow(i + 1, MM - 2) % MM;
            }
        }

        static ll mpow(ll x, ll n) {
            ll ans = 1;
            while (n != 0) {
                if (n & 1) ans = ans * x % MM;
                x = x * x % MM;
                n = n >> 1;
            }
            return ans;
        }

        ll operator()(ll a, ll b) const {
            return this->comb(a, b);
        }

        ll comb(ll a, ll b) const {
            if (a == 0 && b == 0)return 1;
            if (a < b || a < 0 || b < 0)return 0;
            ll const tmp = ifac[a - b] * ifac[b] % MM;
            return tmp * fac[a] % MM;
        }

    }comb;

    ll digit(ll n, ll b = 10) {
        if (n == 0)
            return 1;

        ll d = 0;
        while (n > 0) {
            d++;
            n /= b;
        }

        return d;
    }
}  // namespace math

struct UnionFind {
    vector<ll> data;
    UnionFind(ll size) : data(size, -1) {}
    bool unionSet(ll x, ll y) {
        x = root(x);
        y = root(y);
        if (x != y) {
            if (data[y] < data[x]) swap(x, y);
            data[x] += data[y];
            data[y] = x;
        }
        return x != y;
    }
    bool findSet(ll x, ll y) { return root(x) == root(y); }
    ll root(ll x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
    ll size(ll x) { return -data[root(x)]; }
};

ll bound(function<bool(ll)> f, ll ng, ll ok) {
    while (abs(ng - ok) > 1) {
        ll mid = (ng + ok) / 2;
        if (f(mid))
            ok = mid;
        else
            ng = mid;
    }

    return ok;
}

//value, weight
ll knapsack(vector<pair<ll, ll>> const& a, ll max_w) {
    ll max_n = a.size();
    vector<ll> table(max_w + 1, 0);

    for (int i = 1; i <= max_n; ++i) {
        ll v = a[i].first;
        ll w = a[i].second;
        if (w <= max_w && table[w] < v)
            table[w] = v;
        for (int j = 1; j <= max_w - w; j++) {
            if (table[j] != 0 && table[w + j] < table[j] + v)
                table[w + j] = table[j] + v;
        }
    }

    return *max_element(all(table));
}

//https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a
const int MAX = 510000;
const int MOD = 1000000007;

ll fac[MAX], finv[MAX], inv[MAX];
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(ll n, ll k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

//https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}


//https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int f(std::array<int, 4> a = { 0, 0, 0, 0 }) {
    return a[0] + a[1];
}

int main(void) {
    string S;
    cin >> S;

    if (find(all(S), 'A') != S.end() && find(all(S), 'B') != S.end())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;






    return 0;
}



























