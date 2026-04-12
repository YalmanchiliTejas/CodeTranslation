#include <bits/stdc++.h>
using namespace std;

template <int64_t N>
class modint {
    int64_t x;
public:
    modint(int64_t x = 0) : x((x % N + N) % N) {}
    modint operator-() const { return modint(-x); }
    modint& operator+=(const modint& a) { if ((x += a.x) >= N) x -= N; return *this; }
    modint& operator-=(const modint& a) { if ((x += N - a.x) >= N) x -= N; return *this; }
    modint& operator*=(const  modint& a) { (x *= a.x) %= N; return *this; }
    modint operator+(const modint& a) const { return modint(*this) += a; }
    modint operator-(const modint& a) const { return modint(*this) -= a; }
    modint operator*(const modint& a) const { return modint(*this) *= a; }
    modint pow(int64_t t) const {
        if (not t) return 1;
        modint a = pow(t >> 1); a *= a;
        if (t & 1) a *= *this;
        return a;
    }
    // for prime mod
    modint inv() const { return pow(N - 2); }
    modint& operator/=(const modint& a) { return (*this) *= a.inv(); }
    modint operator/(const modint& a) const { return modint(*this) /= a; }
    friend ostream& operator<<(ostream& os, const modint& m){ os << m.x; return os; }
};

const int64_t mod = 1e9 + 7;
using mint = modint<mod>;

int main(){
    int n; cin >> n;
    vector<int> a(n); vector<mint> sum(n, 0); mint ans = 0;
    for (auto i = 0; i < n; i++) cin >> a[i];
    for (auto i = n - 1; i >= 0; i--) {
        if(i == n - 1) sum[i] += a[i];
        else sum[i] += (mint)a[i] + sum[i + 1];
    }
    for (auto i = 0; i < n - 1; i++) ans += (mint)a[i] * sum[i + 1];
    cout << ans << endl;
    return 0;
}