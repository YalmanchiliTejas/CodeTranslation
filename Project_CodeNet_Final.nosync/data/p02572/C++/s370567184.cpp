#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* struct for mod Calculation*/
struct mint {
        ll x;
        mint(ll x = 0):x((x % mod + mod) % mod) {}
        mint operator-() const { return mint(-x); }
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
        mint pow(ll t) const {
            if (!t) return 1;
            mint a = pow(t >> 1);
            a *= a;
            if (t & 1) a *= *this;
            return a;
        }
        // for prime mod
        mint inv() const {
            return pow(mod - 2);
        }
        mint& operator/=(const mint a) {
            return (*this) *= a.inv();
        }
        mint operator/(const mint a) const {
            mint res(*this);
            return res /= a;
        }
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}
/* global variables */
vector<mint> a;
int N;
/* function */
void input() {
    cin >> N;
    a.resize(N);
    for (int i = 0; i < N; i++) {
        int b; cin >> b;
        a[i] = b;
    }
}
void solve1() {
    vector<mint> sum(N+1);
    sum[0] = 0;
    for (int i = 0; i < N; i++) {
        sum[i+1] += sum[i] + a[i];
    }

    mint ans = 0;
    for (int i = 0; i < N-1; i++) {
        ans += a[i] * (sum[N] - sum[i+1]);
    }
    cout << ans << '\n';
}
void solve2() {
    // ex a = {3, 1, 4}
    //   | 1 | 2 | 3
    //  1| 9 | 3 | 12
    //  2| 3 | 1 | 4
    //  3| 12| 4 | 16
    // ans = (3 + 4 + 12) * 2 + (9 + 1 + 16)
    // ans = (\sigma ai) * 2 - (\sigma (ai ** 2)) * (1/2)
    mint ans = 0;
    mint sum1 = 0;
    mint sum2 = 0;
    for (int i = 0; i < N; i++) {
        sum1 += a[i];
        sum2 += a[i] * a[i];
    }
    ans += sum1 * sum1 - sum2;
    ans /= 2;
    cout << ans << '\n';
}
/* main */
int main(){
    input();
    // solve1();
    solve2();
}
