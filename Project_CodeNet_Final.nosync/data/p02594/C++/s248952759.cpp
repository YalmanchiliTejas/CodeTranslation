#include <bits/stdc++.h>
//#define int ll
#define FOR(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(),(a).end()
#define eb emplace_back

using namespace std;
using ll = long long;
using P = pair<int, int>;
using LP = pair<ll, ll>;
using ILP = pair<int, ll>;
using LIP = pair<ll, int>;
using DP = pair<double, double>;

constexpr int MOD = 1000000007;
constexpr int INF = 1000000000;
constexpr ll LINF = 1000000000000000000;
constexpr int dx[] = {1, 0, -1, 0};
constexpr int dy[] = {0, 1, 0, -1};
constexpr int ddx[] = {1, 1, 0, -1, -1, -1, 0, 1};
constexpr int ddy[] = {0, 1, 1, 1, 0, -1, -1, -1};

template <typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
    for(int i = 0; i < (int)v.size(); i++) {
        if(i) os << ' ';
        os << v.at(i);
    }
    return os;
}

template <typename T>
vector<T>& vecin(vector<T>& v, int n) {
    for(int i = 0; i < n; i++) {
        cin >> v.at(i);
    }
    return v;
}

template <typename T>
void ln(T a) {
    cout << a << '\n';
}

void Yes(bool b) {
    ln(b? "Yes" : "No");
}

int extgcd(int a, int b, int& x, int&y) {
    int d = a;
    if(b != 0) {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    }else {
        x = 1;
        y = 0;
    }
    return d;
}

int inv(int a, int mod) {
    int x, y;
    extgcd(a, mod, x, y);
    return (x + mod) % mod;
}

template <typename T>
T free_pow(T x, int n) {
    T res = T(1);
    while(n > 0) {
        if(n & 1) res *= x;
        x *= x;
        n >>= 1;
    }
    return res;
}

template<int mod>
struct modint {
    int val;

    modint() {
        val = 0;
    }
    modint(int _val) {
        val = ((_val % mod) + mod) % mod;
    }

    bool operator==(const modint &rhs) const {return val == rhs.val;}
    bool operator<(const modint &rhs) const {return val < rhs.val;}
    modint operator+(const modint &rhs) const {return modint<mod>(val + rhs.val);}
    modint operator-(const modint &rhs) const {return modint<mod>(val - rhs.val);}
    modint operator*(const modint &rhs) const {return modint<mod>((int)((ll)val * rhs.val % mod));}
    modint operator/(const modint &rhs) const {return modint<mod>((int)((ll)val * inv(rhs.val, mod) % mod));}
    modint& operator+=(const modint &rhs) {
        val = (val + rhs.val) % mod;
        return *this;
    }
    modint& operator-=(const modint &rhs) {
        val = (val - rhs.val + mod) % mod;
        return *this;
    }
    modint& operator*=(const modint &rhs) {
        val = (int)(((ll)val * rhs.val) % mod);
        return *this;
    }
    modint& operator/=(const modint &rhs) {
        val = (int)((ll)val * inv(rhs.val, mod) % mod);
        return *this;
    }
    modint& operator++() {
        val = (val + 1) % mod;
        return *this;
    }
    modint operator++(signed) {
        modint<mod> m = *this;
        val = (val + 1) % mod;
        return m;
    }
    modint& operator--() {
        val = (val + mod - 1) % mod;
        return *this;
    }
    modint operator--(signed) {
        modint<mod> m = *this;
        val = (val + mod - 1) % mod;
        return m;
    }
};

struct UniTree {
    vector<int> par, rank, sz;

    UniTree(int n) {
        par.resize(n);
        rank.resize(n, 0);
        sz.resize(n, 1);
        for(int i = 0; i < n; i++) {
            par.at(i) = i;
        }
    }

    int root(int x) {
        if(par.at(x) == x) return x;
        else return par.at(x) = root(par.at(x));
    }

    void merge(int x, int y) {
        x = root(x);
        y = root(y);
        if(x == y) return;
        if(rank.at(x) < rank.at(y)) {
            par.at(x) = y;
            sz.at(y) += sz.at(x);
        }else {
            par.at(y) = x;
            if(rank.at(x) == rank.at(y)) rank.at(x)++;
            sz.at(x) += sz.at(y);
        }
    }
    
    bool same(int x, int y) {
        return root(x) == root(y);
    }

    int siz(int x) {
        return sz.at(root(x));
    }
};

template <typename T>
struct Vect {
    T x, y;
    Vect() {
        x = 0;
        y = 0;
    }
    Vect(T x, T y) {
        this->x = x;
        this->y = y;
    }

    int posi() const {
        if(x == 0 && y == 0) exit(1);
        if(x > 0 && y == 0) return 0;
        if(x > 0 && y > 0) return 1;
        if(x == 0 && y > 0) return 2;
        if(x < 0 && y > 0) return 3;
        if(x < 0 && y == 0) return 4;
        if(x < 0 && y < 0) return 5;
        if(x == 0 && y < 0) return 6;
        if(x > 0 && y < 0) return 7;
        return -1;
    }

    bool operator<(const Vect& rhs) {
        int p1 = posi();
        int p2 = rhs.posi();
        if(p1 != p2) return p1 < p2;
        return rhs.x * y < x * rhs.y;
    }
};

template<typename T>
struct SegTree {
    using Func = function<T(T, T)>;
    int n;
    vector<T> dat;
    Func func;
    T low;

    SegTree(vector<T> a, Func _func, T _low) {
        int sz = a.size();
        n = 1;
        low = _low;
        func = _func;
        while(n < sz) n *= 2;
        dat.resize(n * 2 - 1, low);
        rep(i, sz) {
            dat.at(i + n - 1) = a.at(i);
        }
        for(int i = n - 2; i >= 0; i--) {
            dat.at(i) = func(dat.at(i * 2 + 1), dat.at(i * 2 + 2));
        }
    }

    void update(int k, T val) {
        k += n - 1;
        dat.at(k) = val;
        while(k > 0) {
            k = (k - 1) / 2;
            dat.at(k) = func(dat.at(k * 2 + 1), dat.at(k * 2 + 2));
        }
    }

    T _query(int a, int b, int k, int l, int r) {
        if(r <= a || b <= l) return low;
        if(a <= l && r <= b) return dat.at(k);
        T vl = _query(a, b, k * 2 + 1, l, (l + r) / 2);
        T vr = _query(a, b, k * 2 + 2, (l + r) / 2, r);
        return func(vl, vr);
    }

    T query(int a, int b) {
        return _query(a, b, 0, 0, n);
    }
};

signed main() {
    int x;
    cin >> x;
    Yes(x >= 30);
}
