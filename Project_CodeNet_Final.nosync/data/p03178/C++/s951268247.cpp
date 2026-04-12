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

mint dp[100005][100][2];

void solve() {
    dp[0][0][0] = 1;

    string K;
    int D;
    cin >> K >> D;
    const int M = sz(K);
    each(c, K)c -= '0';
    rep(i, M) rep(j, D) rep(k, 2) {
        rep(d, 10) {
            if (d > K[i] && !k)continue;
            int nk = !!(d < K[i] || k);
            int nj = (j + d) % D;
            dp[i + 1][nj][nk] += dp[i][j][k];
        }
    }
    cout << (dp[M][0][0] + dp[M][0][1] - 1) << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(15);
	solve();
	return 0;
}