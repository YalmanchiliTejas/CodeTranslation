#include <bits/stdc++.h>
using namespace std;

#define d(x) cerr << #x ":" << x << endl;
#define dd(x, y) cerr << "(" #x "," #y "):(" << x << "," << y << ")" << endl
#define rep(i, n) for (int i = (int)(0); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define dump(v)                  \
    cerr << #v ":[ ";            \
    for (auto macro_vi : v) {    \
        cerr << macro_vi << " "; \
    }                            \
    cerr << "]" << endl;
#define ddump(v)                           \
    cerr << #v ":" << endl;                \
    for (auto macro_row : v) {             \
        cerr << "[";                       \
        for (auto macro__vi : macro_row) { \
            cerr << macro__vi << " ";      \
        }                                  \
        cerr << "]" << endl;               \
    }
using lint       = long long;
const int INF    = 1e9;
const lint LINF  = 1e18;
const double EPS = 1e-10;

const int mod = 1000000007;
struct mint {
    long long x;
    mint(long long x = 0) : x((x % mod + mod) % mod) {}
    mint& operator+=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += mod - a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const mint a) {
        (x *= a.x) %= mod;
        return *this;
    }
    mint operator+(const mint a) const {
        mint res(*this);
        return res += a;
    }
    mint operator-(const mint a) const {
        mint res(*this);
        return res -= a;
    }
    mint operator*(const mint a) const {
        mint res(*this);
        return res *= a;
    }
    mint pow(long long t) const {
        if (!t) return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t & 1) a *= *this;
        return a;
    }

    // for prime mod
    mint inv() const { return pow(mod - 2); }
    mint& operator/=(const mint a) { return (*this) *= a.inv(); }
    mint operator/(const mint a) const {
        mint res(*this);
        return res /= a;
    }
};

int main() {
    string K;
    int D;
    cin >> K >> D;
    int N = K.size();

    vector<vector<vector<mint>>> cnt(
        N + 1, vector<vector<mint>>(2, vector<mint>(D, 0)));
    cnt[0][0][0] = 1;

    rep(i, N) rep(le, 2) rep(mo, D) {
        int a = int(K[i] - '0');
        for (int x = 0; x < (le ? 10 : a + 1); x++) {
            cnt[i + 1][le || (x < a)][(mo + x) % D] += cnt[i][le][mo];
        }
    }

    cout << (cnt[N][0][0] + cnt[N][1][0] - 1).x << endl;
    return 0;
}