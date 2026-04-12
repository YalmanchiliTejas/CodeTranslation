#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <queue>
#include <deque>
#include <stack>
#include <fstream>
#include <cmath>
#include <random>
#include <complex>
#include <functional>
#include <bitset>
#include <sstream>
#include <cassert>
#include <time.h>

#define ll int64_t
#define Rep(i, n) for (ll i = 0; i < n; i++)
using namespace std;
typedef vector<ll> vec;
typedef vector<vec> mat;

const ll inf = 1LL << 60;

template<class T> inline void chmin(T& a, T b) {
    if (a > b) {
        a = b;
    }
}
template<class T> inline void chmax(T& a, T b) {
    if (a < b) {
        a = b;
    }
}
void printvec (vec &v) {
    Rep (i, (ll)v.size()) {
        cout << v[i] << " \n"[i+1 == (ll)v.size()];
    }
}

const int MOD = 1e9+7;
class mint {
    ll x;
public:
    mint(ll x = 0) : x((x % MOD + MOD) % MOD) {}
    
    mint operator -() const {
        return mint(-x);
    }
    
    mint &operator +=(const mint &a) {
        if ((x += a.x) >= MOD) x -= MOD;
        return *this;
    }

    mint &operator -=(const mint &a) {
        if ((x += MOD - a.x) >= MOD) x -= MOD;
        return *this;
    }

    mint &operator *=(const mint &a) {
        (x *= a.x) %= MOD;
        return *this;
    }

    mint operator +(const mint &a) const {
        mint res(*this);
        return res += a;
    }

    mint operator-(const mint &a) const {
        mint res(*this);
        return res -= a;
    }

    mint operator *(const mint &a) const {
        mint res(*this);
        return res *= a;
    }

    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t & 1) a *= *this;
        return a;
    }

    // for prime mod
    mint inv() const {
        return pow(MOD - 2);
    }

    mint &operator /=(const mint &a) {
        return (*this) *= a.inv();
    }

    mint operator /(const mint &a) const {
        mint res(*this);
        return res /= a;
    }

    friend ostream &operator<<(ostream& os, const mint &m) {
        os << m.x;
        return os;
    }
};


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;
    vec A(N);
    mint s(0);
    Rep (i, N) {
        cin >> A[i];
        s += mint(A[i]);
    }

    mint ans(0);
    Rep (i, N) {
        s -= mint(A[i]);
        ans += mint(A[i]) * s;
    }

    cout << ans << endl;
}