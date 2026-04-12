#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
using namespace std;
#define FOR(i,j,k) for(int (i)=(j);(i)<(int)(k);++(i))
#define rep(i,j) FOR(i,0,j)
#define each(x,y) for(auto &(x):(y))
#define mp make_pair
#define MT make_tuple
#define all(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<(x)<<endl
#define smax(x,y) (x)=max((x),(y))
#define smin(x,y) (x)=min((x),(y))
#define MEM(x,y) memset((x),(y),sizeof (x))
#define sz(x) (int)(x).size()
#define RT return
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

template<int MOD>
class ModInt {
public:
    ModInt() :value(0) {}
    ModInt(long long val) :value((int)(val<0 ? MOD + val % MOD : val % MOD)) { }

    ModInt& operator+=(ModInt that) {
        value = value + that.value;
        if (value >= MOD)value -= MOD;
        return *this;
    }
    ModInt& operator-=(ModInt that) {
        value -= that.value;
        if (value<0)value += MOD;
        return *this;
    }
    ModInt& operator*=(ModInt that) {
        value = (int)((long long)value * that.value % MOD);
        return *this;
    }
    ModInt &operator/=(ModInt that) {
        return *this *= that.inverse();
    }
    ModInt operator+(ModInt that) const {
        return ModInt(*this) += that;
    }
    ModInt operator-(ModInt that) const {
        return ModInt(*this) -= that;
    }
    ModInt operator*(ModInt that) const {
        return ModInt(*this) *= that;
    }
    ModInt operator/(ModInt that) const {
        return ModInt(*this) /= that;
    }
    ModInt pow(long long k) const {
        ModInt n = *this, res = 1;
        while (k) {
            if (k & 1)res *= n;
            n *= n;
            k >>= 1;
        }
        return res;
    }
    ModInt inverse() const {
        long long a = value, b = MOD, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b;
            swap(a, b);
            u -= t * v;
            swap(u, v);
        }
        return ModInt(u);
    }
    int toi() const { return value; }

private:
    int value;
};
typedef ModInt<1000000007> mint;
ostream& operator<<(ostream& os, const mint& x) {
    os << x.toi();
    return os;
}

namespace comb {
    const int N = 200010;
    mint fact[N];
    mint rev[N];

    void init() {
        fact[0] = 1;
        for (int i = 1; i < N; ++i)fact[i] = fact[i - 1] * i;
        for (int i = 0; i < N; ++i)rev[i] = fact[i].inverse();
    }

    mint C(int n, int r) {
        if (n < r)return 0;
        return fact[n] * rev[r] * rev[n - r];
    }

    mint H(int n, int r) {
        return C(n + r - 1, r);
    }

    mint P(int n, int r) {
        assert(n >= r);
        return fact[n] * rev[n - r];
    }

    mint catalan(int n) {
        return fact[2 * n] * rev[n + 1] * rev[n];
    }
}

mint f(int n, int m, int K) {
    mint res;
    rep(x, n) {
        res += mint(x) * x;
        res -= mint(n - x - 1)*x;
    }
    res *= comb::C(n*m - 2, K - 2)*m*m;
    return res;
}

void solve() {
    comb::init();

    int N, M, K;
    cin >> N >> M >> K;
    mint ans = f(N, M, K) + f(M, N, K);
    cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(15);
	solve();
	return 0;
}