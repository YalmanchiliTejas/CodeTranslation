#ifdef _MSC_VER
#include "stdc++.h"
#endif
#ifdef __GNUC__
#include<bits/stdc++.h>
#endif
using namespace std;

using ll = long long;

//vector
using vi = vector<int>;
using vii = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;

//constant
const double EPS = 1e-10;

#define REP(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, s, e) for (ll i = s; i < e; i++)
#define ALL(x) (x).begin(),(x).end()
#define RALL(x) (x).rbegin(), (x).rend()

//debug
#define DUMP(x)  cerr << #x << " = " << (x) << endl;
#define DEBUG(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl;

// vector
//template<typename T> vector<vector<T>> vv(ll H, ll W, T v) { return vector<vector<T>> vec(H, vector<T>(W, v)); }

// view vector
template<typename T> void view(T e) { cout << e << endl; }
template<typename T> void view(const vector<T>& v) { for (const auto& e : v) { cout << e << " "; } cout << endl; }
template<typename T> void view(const vector<vector<T> >& vv) { for (const auto& v : vv) { view(v); } }

// DP
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }


const ll MOD = 1000000007;
const ll inf = 1LL << 60;

struct Mint {
    ll v;
    ll _mod;
    bool init = false;
    Mint() : v(0), _mod(MOD) {}
    Mint(signed v, ll _mod = MOD) : v(v), _mod(_mod) {}
    Mint(ll t, ll _mod = MOD, bool init=false) : _mod(_mod), init(init) {
        v = t % _mod;
        if (v < 0)
            v += _mod;
    }

    Mint pow(ll k) {
        Mint res(1, _mod), tmp(v, _mod);
        while (k) {
            if (k & 1)
                res *= tmp;
            tmp *= tmp;
            k >>= 1;
        }
        return res;
    }
    static Mint add_identity(ll mod = MOD) { return Mint(0, mod); }
    static Mint mul_identity(ll mod = MOD) { return Mint(1, mod); }
    Mint inv() { return pow(_mod - 2); }

    Mint& operator+=(Mint a) {
        v += a.v;
        if (v >= _mod)
            v -= _mod;
        return *this;
    }
    Mint& operator-=(Mint a) {
        v += _mod - a.v;
        if (v >= _mod)
            v -= _mod;
        return *this;
    }
    Mint& operator*=(Mint a) {
        v = v * a.v % _mod;
        return *this;
    }
    Mint& operator/=(Mint a) { return (*this) *= a.inv(); }

    Mint operator+(Mint a) const { return Mint(v, _mod) += a; };
    Mint operator-(Mint a) const { return Mint(v, _mod) -= a; };
    Mint operator*(Mint a) const { return Mint(v, _mod) *= a; };
    Mint operator/(Mint a) const { return Mint(v, _mod) /= a; };

    Mint operator-() const { return v ? Mint(_mod - v, _mod) : Mint(v, _mod); }

    bool operator==(const Mint a) const { return v == a.v; }
    bool operator!=(const Mint a) const { return v != a.v; }
    bool operator<(const Mint a) const { return v < a.v; }
};
ostream& operator<<(ostream& os, Mint m) { return os << m.v; }

Mint nCk(int n, int k) {
    Mint ret = 1;
    for (int i = n; i > n - k; --i) {
        ret *= i;
    }
    for (int i = 1; i <= k; ++i) {
        ret /= i;
    }
    return ret;
}

using vmi = vector<Mint>;
using vvmi = vector<vmi>;
using vvvmi = vector<vvmi>;

// ***************************************

string K;
int D;

vvvmi dp;


Mint rec(int digit, bool smaller, int modD) {
    if (dp[digit][smaller][modD].init == false) return dp[digit][smaller][modD];
    if (digit >= K.size()) return dp[digit][smaller][modD] = Mint(modD == 0);

    int lim = smaller ? 9 : (K[digit] - '0');
    Mint ret(0);
    REP(i, lim + 1) {
        ret += rec(digit + 1, smaller || (i < lim), (modD + i) % D);
    }

    return dp[digit][smaller][modD] = ret;
}

int main() {

    cin >> K >> D;
    dp.resize(K.size() + 1, vvmi(2, vmi(D + 1, {0, MOD, true})));

    auto ans = rec(0, 0, 0) - 1;

    cout << ans.v << endl;


    return 0;
}