#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <numeric>
#include <list>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <tuple>
#include <deque>
#include <complex>

using namespace std;

/*
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
*/

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<long long, long long> pll;
typedef vector<pll> vpll;

typedef long double ld;
typedef vector<ld> vld;

typedef vector<bool> vb;

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define reps(i, n) for (ll i = 1; i <= (n); i++)
#define rrep(i, n) for (ll i = (n) - 1; i >= 0; i--)
#define rreps(i, n) for (ll i = (n); i >= 1; i--)
#define all(v) (v).begin(), (v).end()

template <class T> void chmin(T& a, T b) { a = min(a, b);}
template <class T> void chmax(T& a, T b) { a = max(a, b);}

constexpr int INF = 1 << 30;
constexpr ll INFL = 1LL << 60;
constexpr ll MOD = 998244353;
constexpr ld EPS = 1e-12;
ld PI = acos(-1.0);

struct mint {
	ll x;
	mint(ll x=0):x((x%MOD+MOD)%MOD){}
	mint operator-() const { return mint(-x);}
	mint& operator+=(const mint a) {if ((x+=a.x)>=MOD) x-=MOD; return *this;}
	mint& operator-=(const mint a) {if ((x+=MOD-a.x)>=MOD) x-=MOD; return *this;}
	mint& operator*=(const mint a) {(x*=a.x)%=MOD; return *this;}
	mint operator+(const mint a) const {mint res(*this); return res+=a;}
	mint operator-(const mint a) const {mint res(*this); return res-=a;}
	mint operator*(const mint a) const {mint res(*this); return res*=a;}
	mint pow(ll t) const {
		if (!t) return 1;
		mint a = pow(t>>1);
		a *= a;
		if (t&1) a *= *this;
 		return a;
	}

	// For prime mod.
	// Do not use if MOD is not prime number !!
	mint inv() const { return pow(MOD-2);}
	mint& operator/=(const mint a) { return (*this) *= a.inv();}
	mint operator/(const mint a) const {mint res(*this); return res/=a;}
};

typedef vector<mint> vm;
typedef vector<vm> vvm;
void solve() {
    ll n, s;
    cin >> n >> s;
    vll a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    vector<vvm> dp(n + 1, vvm(s + 1, vm(3)));
    dp[0][0][0] = 1;
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j <= s; j++) {
            dp[i + 1][j][0] += dp[i][j][0];
            dp[i + 1][j][1] += dp[i][j][0] + dp[i][j][1];
            dp[i + 1][j][2] += dp[i][j][0] + dp[i][j][1] + dp[i][j][2];
            if(j + a[i] <= s) {
                dp[i + 1][j + a[i]][1] += dp[i][j][0] + dp[i][j][1];
                dp[i + 1][j + a[i]][2] += dp[i][j][0] + dp[i][j][1];
            }
        }
    }
    cout << dp[n][s][2].x << endl;
    return;
}

int main() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}