#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repr(i, n) for(int i = (n-1); i >= 0; --i)

typedef long long ll;
typedef pair<int, int> P;

const int MAX = 200005;
const int INF = 1001001001;
const int MOD = 998244353;

struct mint {
    long long x;
    mint(long long x=0):x(x % MOD + (0 <= x ? 0 : MOD)) {}
    mint operator-() const { return mint(-x); }
    mint& operator+=(const mint& a) { if ((x += a.x) >= MOD) x -= MOD; return *this; }
    mint& operator-=(const mint& a) { if ((x -= a.x) < 0) x += MOD; return *this; }
    mint& operator*=(const mint& a) { (x *= a.x) %= MOD; return *this; }
    mint operator+(const mint& a) const { return mint(x) += a; }
    mint operator-(const mint& a) const { return mint(x) -= a; }
    mint operator*(const mint& a) const { return mint(x) *= a; }

    // for prime mod
    mint inv() const {
        long long a = x, b = MOD, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        return mint(u);
    }
    mint& operator/=(const mint& a) { return *this *= a.inv(); }
    mint operator/(const mint& a) const { return mint(x) /= a; }
};
istream& operator>>(istream& is, const mint& a){ return is >> a.x; }
ostream& operator<<(ostream& os, const mint& a){ return os << a.x; }

int main(){
    int N, S;
    cin >> N >> S;

    vector<int> A(N);
    for (auto &i : A) cin >> i;

    vector<mint> dp(S+1);
    dp[0] = 1;
    mint ans = 0;
    rep(i, N) {
        repr(j, S+1) {
            int nj = j + A[i];
            if (nj <= S) dp[nj] += dp[j];
        }
        ans += dp[S];
        dp[0] += 1;
    }

    cout << ans << endl;
}