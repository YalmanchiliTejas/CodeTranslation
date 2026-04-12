#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

template<int64_t MOD> struct Mint {
    int64_t v;
    Mint() { v = 0; }
    Mint(int64_t x) { v = x % MOD; if(v < 0)  v += MOD; }

    Mint operator-() { return Mint{-v}; };
    Mint operator+(Mint x) { return Mint(v + x.v); };
    Mint operator-(Mint x) { return Mint(v - x.v); };
    Mint operator*(Mint x) { return Mint(v * x.v); };
    Mint operator/(Mint x) { return Mint(v * pow(x.v, MOD-2).v); };

    Mint& operator+=(Mint x) { return *this = (*this + x); };
    Mint& operator-=(Mint x) { return *this = (*this - x); };
    Mint& operator*=(Mint x) { return *this = (*this * x); };
    Mint& operator/=(Mint x) { return *this = (*this / x); };

    static Mint pow(Mint base, int64_t exp) {
        if(exp == 0)  return Mint(1);
        return pow(base*base, exp/2) * (exp&1 ? base : Mint(1));
    }

    friend ostream& operator<<(ostream& os, Mint x) { return os << x.v; }
};
using mint = Mint<998244353>;

template<class T> struct Polynomial {
    vector<T> p;

    Polynomial() {}
    Polynomial(int n) { p.assign(n, T{}); }
    Polynomial(int n, T val) { p.assign(n, val); }
    Polynomial(vector<T> v) : p(v) {}

    inline int size() { return p.size(); }
    T& operator[](int i) { return p[i]; }
    auto begin() { return p.begin(); }
    auto end() { return p.end(); }

    Polynomial operator+=(Polynomial x) {
        int n = max(size(), x.size());
        p.resize(n); x.p.resize(n);
        for(int i=0; i<n; i++) p[i] += x[i];
        return *this;
    }

    Polynomial operator-=(Polynomial x) {
        int n = max(size(), x.size());
        p.resize(n); x.p.resize(n);
        for(int i=0; i<n; i++) p[i] -= x[i];
        return *this;
    }

    // !!! O(n*m) !!!
    Polynomial operator*=(Polynomial x) {
        int n = size();
        int m = x.size();
        auto res = Polynomial(n+m-1);
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                res.p[i+j] += p[i] * x[j];
            }
        }
        return res;
    }

    Polynomial operator>>(int c) {
        int n = size();
        auto res = Polynomial(n+c);
        for(int i=0; i<n; i++) res.p[i+c] = p[i];
        return res;
    }

    Polynomial operator<<(int c) {
        int n = size();
        assert(n-c>0);
        auto res = Polynomial(n-c);
        for(int i=c; i<n; i++) res.p[i-c] = p[i];
        return res;
    }

    Polynomial operator+(Polynomial x) { return Polynomial(p) += x; }
    Polynomial operator-(Polynomial x) { return Polynomial(p) -= x; }
    Polynomial operator*(Polynomial x) { return Polynomial(p) *= x; }

    friend istream& operator>>(istream& is, Polynomial& x) {
        for(auto& e : x.p) is >> e;
        return is;
    }

    friend ostream& operator<<(ostream& os, Polynomial x) {
        for(auto& e : x.p) os << e << " \n"[&e==&x.p.back()];
        return os;
    }
};

int main() {
    lint n, s;
    cin >> n >> s;

    vector<lint> a(n);
    for(auto& elem : a)  cin >> elem;
    reverse(a.begin(), a.end());

    Polynomial<mint> p(s+1);

    Polynomial<mint> ans(s+1);
    for(int i=0; i<n; i++) {
        p[0] += 1;
        p += (p>>a[i]);
        p.p.resize(s+1);
        ans += p;
    }

    cout << ans[s] << endl;
}