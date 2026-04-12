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
/* function */
/* main */
int main(){
    int N;
    cin >> N;
    vector<mint> a(N);
    for (int i = 0; i < N; i++) {
        int b; cin >> b;
        a[i] = b;
    }

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
