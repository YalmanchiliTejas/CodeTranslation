#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ALL(x) (x).begin(),(x).end()
const int IINF = 1e9;
const LL LINF = 1e18;
const LL MOD = 1e9+7;

namespace ModCalc {
template <LL mod> struct ModInt {
    LL x;

    ModInt() : x(0) {}
    ModInt(LL y) : x(0 < y ? y%mod : (mod - (-y)%mod)%mod) {}

    ModInt &operator=(const ModInt &p) {
        x = p.x;
        return *this;
    }
    ModInt &operator+=(const ModInt &p) {
        x = (x + p.x + mod)%mod;
        return *this;
    }
    ModInt &operator-=(const ModInt &p) {
        x = (x - p.x + mod)%mod;
        return *this;
    }
    ModInt &operator*=(const ModInt &p) {
        x = (x * p.x)%mod;
        return *this;
    }

    ModInt operator+(const ModInt &p) const {return ModInt(x + p.x);}
    ModInt operator-(const ModInt &p) const {return ModInt(x - p.x);}
    ModInt operator*(const ModInt &p) const {return ModInt(x * p.x);}

    bool operator==(const ModInt &p) const {return x == p.x;};
    bool operator!=(const ModInt &p) const {return !(*this == p);};

    bool operator<(const ModInt &p) const {return x < p.x;};
    bool operator>(const ModInt &p) const {return p < *this;};
    bool operator<=(const ModInt &p) const {return !(*this > p);};
    bool operator>=(const ModInt &p) const {return !(*this < p);};

    ModInt pow(LL y) const {
        ModInt p = *this;
        ModInt r(1);
        for(;0 < y;) {
            if(y%2 == 1) {
                y--;
                r *= p;
            }else{
                y /= 2;
                p *= p;
            }
        }
        return r;
    }

    ModInt pow(const ModInt &y) const {
        return pow(y.x);
    }

    ModInt operator/(const ModInt &p) const {
        return (*this)*p.pow(mod - 2);
    }
    ModInt &operator/=(const ModInt &p) {
        *this = (*this)/p;
        return *this;
    }

    ModInt operator-() {return ModInt(-x);}

    friend ostream &operator<<(ostream &os, const ModInt &p) {
        return os << p.x;
    }
 
    friend istream &operator>>(istream &is, ModInt &a) {
        int64_t t;
        is >> t;
        a = ModInt(t);
        return is;
    }
};

template <LL mod>
const ModInt<mod> operator+(const ModInt<mod> &p, const LL q) {
    ModInt<mod> r(q);
    return p + r;
}
template <LL mod>
const ModInt<mod> operator+(const LL p, const ModInt<mod> &q) {
    ModInt<mod> r(p);
    return r + q;
}
template <LL mod>
const ModInt<mod> &operator+=(ModInt<mod> &p, const LL q) {
    ModInt<mod> r(q);
    p += r;
    return p;
}

template <LL mod>
const ModInt<mod> operator-(const ModInt<mod> &p, const LL q) {
    ModInt<mod> r(q);
    return p - r;
}
template <LL mod>
const ModInt<mod> operator-(const LL p, const ModInt<mod> &q) {
    ModInt<mod> r(p);
    return r - q;
}
template <LL mod>
const ModInt<mod> &operator-=(ModInt<mod> &p, const LL q) {
    ModInt<mod> r(q);
    p -= r;
    return p;
}

template <LL mod>
const ModInt<mod> operator*(const ModInt<mod> &p, const LL q) {
    ModInt<mod> r(q);
    return p * r;
}
template <LL mod>
const ModInt<mod> operator*(const LL p, const ModInt<mod> &q) {
    ModInt<mod> r(p);
    return r * q;
}
template <LL mod>
const ModInt<mod> &operator*=(ModInt<mod> &p, const LL q) {
    ModInt<mod> r(q);
    p *= r;
    return p;
}

template <LL mod>
const ModInt<mod> operator/(const ModInt<mod> &p, const LL q) {
    ModInt<mod> r(q);
    return p/r;
}
template <LL mod>
const ModInt<mod> operator/(const LL p, const ModInt<mod> &q) {
    ModInt<mod> r(q);
    return r/q;
}
template <LL mod>
const ModInt<mod> &operator/=(ModInt<mod> &p, const LL q) {
    ModInt<mod> r = p/q;
    p /= r;
    return p;
}

template <LL mod>
bool operator==(ModInt<mod> &p, const LL q) {
    ModInt<mod> r(q);
    return p == r;
}
template <LL mod>
bool operator==(const LL p, ModInt<mod> &q) {
    ModInt<mod> r(p);
    return r == q;
}
template <LL mod>
bool operator!=(ModInt<mod> &p, const LL q) {return !(p == q);}
template <LL mod>
bool operator!=(const LL p, ModInt<mod> &q) {return !(p == q);}

template <LL mod>
bool operator<(ModInt<mod> &p, const LL q) {
    ModInt<mod> r(q);
    return p < r;
}
template <LL mod>
bool operator<(const LL p, ModInt<mod> &q) {
    ModInt<mod> r(p);
    return r < q;
}
template <LL mod>
bool operator>(ModInt<mod> &p, const LL q) {return q < p;}
template <LL mod>
bool operator>(const LL p, ModInt<mod> &q) {return q < p;}
template <LL mod>
bool operator<=(ModInt<mod> &p, const LL q) {return !(p > q);}
template <LL mod>
bool operator<=(const LL p, ModInt<mod> &q) {return !(p > q);}
template <LL mod>
bool operator>=(ModInt<mod> &p, const LL q) {return !(p < q);}
template <LL mod>
bool operator>=(const LL p, ModInt<mod> &q) {return !(p < q);}

using mint = ModInt<MOD>;
};

using namespace ModCalc;

int main() {
    int N;
    cin >> N;
    vector<mint> v(N);
    REP(i, N) {
        cin >> v[i];
    }

    vector<mint> s(N);
    s[N - 1] = 0;
    for(int i = N - 2;0 <= i;i--) {
        s[i] = v[i + 1] + s[i + 1];
    }

    mint res = 0;
    REP(i, N - 1) {
        res += v[i]*s[i];
    }
    cout << res << endl;
    return 0;
}
