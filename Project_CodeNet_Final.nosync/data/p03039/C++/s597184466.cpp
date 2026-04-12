#include <iostream>
#include <vector>
#include <array>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cmath>
#include <iomanip>

using namespace std;
using ll=long long int;

template <typename T>
T powint(T a, ll n) {
    T ret = 1;
    while (n > 0) {
        if (n & 1) ret *= a; 
        a *= a;
        n >>= 1;
    }
    return ret;
}

template <ll mod>
class ModInt {
private:
    ll num;
public:
    ModInt() {};
    ModInt(ll n) { num = n % mod; }
    ModInt inv() const { return powint(*this, mod-2); }
    explicit operator ll() const { return num; }

    ModInt& operator+=(const ModInt& a) {
        num += a.num; 
        if (num >= mod) num -= mod; 
        return *this;
    }
    ModInt& operator-=(const ModInt& a) {
        if (num < a.num) num += mod;
        num -= a.num;
        return *this;
    }
    ModInt& operator*=(const ModInt& a) {
        num = num * a.num % mod;
        return *this;
    }
    ModInt& operator/=(const ModInt& a) { return *this *= a.inv(); }
    friend ModInt operator+(const ModInt& a, const ModInt& b) { return ModInt(a) += b; }
    friend ModInt operator-(const ModInt& a, const ModInt& b) { return ModInt(a) -= b; }
    friend ModInt operator*(const ModInt& a, const ModInt& b) { return ModInt(a) *= b; }
    friend ModInt operator/(const ModInt& a, const ModInt& b) { return ModInt(a) /= b; }

    friend ostream& operator<<(ostream& os, const ModInt& a) { return os << a.num; }
    friend istream& operator>>(istream& is, ModInt& a) {
        ll tmp;
        is >> tmp;
        a.num = tmp % mod;
        return is;
    }
};
using mint = ModInt<1000000007>;
//using mint = ModInt<998244353>;

vector<mint> fact, factinv;
static void fact_reserve(int n)
{
    fact.resize(n + 1);
    factinv.resize(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fact[i] = (ll)fact[i - 1] * i;
    }
    factinv[n] = fact[n].inv();
    for (int i = n; i >= 1; --i) {
        factinv[i - 1] = (ll)factinv[i] * i;
    }
}

mint P(int n, int k) {
    return fact[n] * factinv[n-k];
}
mint C(int n, int k) {
    return fact[n] * factinv[n-k] * factinv[k];
}
mint H(int n, int k) {
    return C(n+k-1, k);
}

mint calc(int n, int m, int k) {
    mint ret = 0;
    for (int d = 1; d < n; ++d) {
        ret += C(n*m-2, k-2) * (n-d) * m * m * d;
    }
    return ret;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    fact_reserve(n*m);

    mint ans = 0;
    ans += calc(n, m, k);
    ans += calc(m, n, k);

    cout << ans << endl;

    return 0;
}
