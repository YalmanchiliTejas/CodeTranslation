#include <bits/stdc++.h>
using namespace std;

template<class T>
bool chmax(T& a, const T& b) {
    if (a < b) { a = b; return true; }
    return false;
}
template<class T>
bool chmin(T& a, const T& b) {
    if (b < a) { a = b; return true; }
    return false;
}

// std::vector Declaration
template<typename T>
vector<T> make_v(size_t a) { return vector<T>(a); }
template<typename T, typename... Ts>
auto make_v(size_t a, Ts... ts) {
    return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}

// std::vector Declaration and Initialization
template<typename T>
vector<T> make_vector(size_t a, T x) { return vector<T>(a, x); }
template<typename T, typename U, typename... Ts>
auto make_vector(size_t a, U b, Ts... ts) {
    return vector<decltype(make_vector<T>(b,ts...))>(a, make_vector<T>(b, ts...));
}

// std::vector Input
template<typename T>
istream& operator>>(istream& is, vector<T>& v) {
    for (auto &e : v) is >> e;
    return is;
}

// std::vector Debug
template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "[";
    bool a = 1;
    for (auto e : v) {
        os << (a ? "" : " ");
        os << e;
        a = 0;
    }
    os << "]";
    return os;
}

// std::array Debug
template<typename T, size_t n>
ostream& operator<<(ostream& os, const array<T, n>& v) {
    os << "[";
    bool a = 1;
    for (auto e : v) {
        os << (a ? "" : " ");
        os << e;
        a = 0;
    }
    os << "]";
    return os;
}

// std::deque Debug
template<typename T>
ostream& operator<<(ostream& os, const deque<T>& d) {
    os << "[";
    bool a = 1;
    for (auto e : d) {
        os << (a ? "" : " ");
        os << e;
        a = 0;
    }
    os << "]";
    return os;
}

// std::pair Debug
template<typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    os << "(" << p.first << " " << p.second << ")";
    return os;
}

// std::set Debug
template<typename T>
ostream& operator<<(ostream& os, const set<T>& st) {
    os << "{";
    bool a = 1;
    for (auto e : st) {
        os << (a ? "" : " ");
        os << e;
        a = 0;
    }
    os << "}";
    return os;
}

// std::multiset Debug
template<typename T>
ostream& operator<<(ostream& os, const multiset<T>& st) {
    os << "{";
    bool a = 1;
    for (auto e : st) {
        os << (a ? "" : " ");
        os << e;
        a = 0;
    }
    os << "}";
    return os;
}

// std::map Debug
template<typename T, typename U>
ostream& operator<<(ostream& os, const map<T, U>& mp) {
    os << "{";
    bool a = 1;
    for (auto e : mp) {
        os << (a ? "" : " ");
        os << e.first << ":" << e.second;
        a = 0;
    }
    os << "}";
    return os;
}

// std::tuple Debug
template<int N, class Tuple>
void out(ostream& os, const Tuple& t){}
template<int N, class Tuple, class H, class ...Ts>
void out(ostream& os, const Tuple& t) {
    if (N) os << " ";
    os << get<N>(t);
    out<N+1,Tuple,Ts...>(os, t);
}
template<class ...Ts>
ostream& operator<<(ostream& os, const tuple<Ts...>& t) {
    os << "(";
    out<0,tuple<Ts...>,Ts...>(os, t);
    os << ")";
    return os;
}

// Debug
#define DUMP(x) cerr<<#x<<" = "<<(x)<<endl

// Weighted edge
template<typename T>
struct edge {
    int src, to;
    T cost;

    edge() {}
    edge(int to, T cost) : src(-1), to(to), cost(cost) {}
    edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

    friend ostream& operator<<(ostream& os, const edge& e) {
        return os << "(" << e.src << "->" << e.to << ":" << e.cost << ")";
    }
};

using LL = int64_t;

#define fs first
#define sc second

const int64_t MOD = 1e9+7;


template<int64_t mod>
struct modint {
    using LL = int64_t;
    LL val;
    modint(LL val=0) : val(((val % mod) + mod) % mod) {}

    const modint operator+() const { return *this; }
    const modint operator-() const { return (-val + mod) % mod; }
    const modint inv() const { return pow(mod-2); }

    modint& operator+=(const modint& rhs) {
        (val += rhs.val) %= mod;
        return *this;
    }
    modint& operator-=(const modint& rhs) {
        return *this += -rhs;
    }
    modint& operator*=(const modint& rhs) {
        (val *= rhs.val) %= mod;
        return *this;
    }
    modint& operator/=(const modint& rhs) {
        return *this *= rhs.inv();
    }

    const modint operator+(const modint& rhs) const {
        return modint(*this) += rhs;
    }
    const modint operator-(const modint& rhs) const {
        return modint(*this) -= rhs;
    }
    const modint operator*(const modint& rhs) const {
        return modint(*this) *= rhs;
    }
    const modint operator/(const modint& rhs) const {
        return modint(*this) /= rhs;
    }

    const modint pow(LL n) const {
        modint ret = 1, tmp = val;
        while (n > 0) {
            if (n & 1) ret *= tmp;
            tmp *= tmp; n >>= 1;
        }
        return ret;
    }

    bool operator==(const modint& rhs) const { return val == rhs.val; }
    bool operator!=(const modint& rhs) const { return !(*this == rhs); }

    friend const modint operator+(const LL& lhs, const modint& rhs) {
        return modint(lhs) + rhs;
    }
    friend const modint operator-(const LL& lhs, const modint& rhs) {
        return modint(lhs) - rhs;
    }
    friend const modint operator*(const LL& lhs, const modint& rhs) {
        return modint(lhs) * rhs;
    }
    friend const modint operator/(const LL& lhs, const modint& rhs) {
        return modint(lhs) / rhs;
    }

    friend bool operator==(const LL& lhs, const modint& rhs) {
        return modint(lhs) == rhs;
    }
    friend bool operator!=(const LL& lhs, const modint& rhs) {
        return modint(lhs) != rhs;
    }

    friend ostream& operator<<(ostream& os, const modint& a) {
        return os << a.val;
    }
    friend istream& operator>>(istream& is, modint& a) {
        LL tmp; is >> tmp;
        a = tmp;
        return is;
    }
};

template<typename Field>
struct Combination {
    vector<Field> _fact, _rfact, _inv;

    Combination(int n) : _fact(n), _rfact(n), _inv(n) {
        _fact[0] = _rfact[n-1] = 1;
        for (int i = 1; i < n; ++i) _fact[i] = _fact[i-1] * i;
        _rfact[n-1] /= _fact[n-1];
        for (int i = n-1; i > 0; --i) _rfact[i-1] = _rfact[i] * i;
        for (int i = 1; i < n; ++i) _inv[i] = _rfact[i] * _fact[i-1];
    }

    inline Field fact(int k) const { return _fact.at(k); }

    inline Field rfact(int k) const { return _rfact.at(k); }

    inline Field inv(int k) const { assert(k != 0); return _inv.at(k); }

    Field P(int n, int r) const {
        if (r < 0 || n < r) return 0;
        return fact(n) * rfact(n-r);
    }

    Field C(int n, int r) const {
        if (r < 0 || n < r) return 0;
        return fact(n) * rfact(r) * rfact(n-r);
    }

    Field H (int n, int r) const {
        return (n == 0 && r == 0) ? 1 : C(n+r-1, r);
    }
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    while (true) {
        int N, X; LL D;
        cin >> N >> D >> X;
        if (N == 0) break;

        using Int = modint<MOD>;

        vector<Int> DC(N+1);
        DC[0] = 1;
        for (int i = 1; i <= N; ++i) {
            DC[i] = DC[i-1] * (D-i+1) / i;
        }

        Combination<Int> comb(2*N+1);

        Int ans = 0;
        for (int k = 1; k <= N; ++k) {
            Int tmp = 0;
            for (int i = 0; i <= k; ++i) {
                tmp += comb.H(k, (N-k)-(X-1)*i) * comb.C(k,i) * (i & 1 ? -1 : 1);
            }
            ans += DC[k] * tmp;
        }

        cout << ans << endl;
    }

    return 0;
}

