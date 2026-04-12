#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repr(i, n) for(int i = (n-1); i >= 0; --i)

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;
typedef pair<int, int> P;

const int MAX = 200005;
const int INF = 1001001001;
const int MOD = 1000000007;

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
    int N;
    cin >> N;

    vector<int> A(N);
    for (auto &i : A) cin >> i;

    vector<mint> sum(N+1);
    rep(i, N) sum[i+1] = sum[i] + A[i];

    mint ans = 0;
    rep(i, N) {
        ans += (sum[N] - sum[i+1]) * A[i];
    }

    cout << ans << endl;
}