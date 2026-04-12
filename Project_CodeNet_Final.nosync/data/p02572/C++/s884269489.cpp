#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;
using ll = long long;

template<typename T>
T pown(T b, ll e) {
    if(e == 0) return 1;
    T p = pown(b, e / 2);
    if(e % 2 == 0) return p * p;
    return p * p * b;
}

template<const int mod>
struct Intmod {
    ll a;
    Intmod(ll a = 0): a(((a % mod) + mod) % mod) {}

    Intmod operator-() const {return Intmod(-a);}

    Intmod& operator+=(const Intmod b) {
        if((a += b.a) >= mod) a -= mod;
        return *this;
    }
    Intmod& operator+=(const ll b) {
        if((a += b) >= Intmod(mod).a) a -= mod;
        return *this;
    }
    Intmod& operator-=(const Intmod b) {
        if((a -= b.a) < 0) a += mod;
        return *this;
    }
    Intmod& operator-=(const ll b) {
        if((a -= Intmod(b).a) < 0) a += mod;
        return *this;
    }
    Intmod& operator*=(const Intmod b) {
        (a *= b.a) %= mod;
        return *this;
    }
    Intmod& operator*=(const ll b) {
        (a *= Intmod(b).a) %= mod;
        return *this;
    }

    template<typename T> Intmod operator+(const T b) const {return Intmod(*this) += b;}
    template<typename T> Intmod operator-(const T b) const {return Intmod(*this) -= b;}
    template<typename T> Intmod operator*(const T b) const {return Intmod(*this) *= b;}

    // Valid for prime mod. pown() needs to be included.
    int i = 0;
    Intmod inv() {
        if(a == 0) throw "Inverse of zero does not exist.";
        if(!i) i = pown(*this, mod - 2).a;
        return Intmod(i);
    }
    Intmod& operator/=(const Intmod b) {return *this *= b.inv();}
    Intmod& operator/=(const ll b) {return *this *= Intmod(b).inv();}
    template<typename T> Intmod operator/(const T b) const {return Intmod(*this) /= b;}
};
template<const int mod> Intmod<mod> operator+(const ll b, Intmod<mod> a) {return a += b;}
template<const int mod> Intmod<mod> operator-(const ll b, Intmod<mod> a) {return a -= b;}
template<const int mod> Intmod<mod> operator*(const ll b, Intmod<mod> a) {return a *= b;}
template<const int mod> Intmod<mod> operator/(const ll b, Intmod<mod> a) {return a /= b;} //Valid for prime mod.

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    const int MOD = 1000000007;

    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a.at(i);

    Intmod<MOD> sum = 0, sum_diag = 0, ans = 1;

    rep(i, n) {
        sum += a.at(i);
        sum_diag -= a.at(i) * a.at(i);
    }

    ans *= sum;
    ans *= sum;
    ans += sum_diag;
    ans /= 2;

    printf("%d\n", ans.a);

    return 0;
}