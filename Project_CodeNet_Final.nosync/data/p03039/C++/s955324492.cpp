#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

template<int64_t MOD> struct Mint {
    int64_t v;
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

template<class T> struct Counting {
    void init(int64_t n) {
        _fact.assign(n+1, 1);
        for(int64_t i = 1; i <= n; i++)  _fact[i] = T(i) * _fact[i-1];
    }

    T fact(int64_t n) {
        assert(0 <= n && n < (int)_fact.size());
        return _fact[n];
    }

    T comb(int64_t n, int64_t k) {
        if(n < k)  return 0;
        return fact(n) / (fact(k) * fact(n-k));
    }

    private:
        vector<T> _fact;
};

const int64_t MOD = 1e9+7;
using mint = Mint<MOD>;
Counting<mint> cnt;

// = = = = = = = = = = = = = = = =
lint n, m, k;

mint multi(lint w, lint h) {
    if(h == 0)  return mint((m - w) * n);
    if(w == 0)  return mint(m * (n - h));
    return mint( (m - w) * 2*(n - h) );
}

int main() {
    cin >> n >> m >> k;
    mint ans(0);

    for(lint w = 0; w < m; w++) {
        for(lint h = 0; h < n; h++) {
            ans += mint(w + h) * multi(w, h);
        }
    }
    cnt.init(200000);
    ans *= cnt.comb(n*m-2, k-2);
    cout << ans << endl;
}