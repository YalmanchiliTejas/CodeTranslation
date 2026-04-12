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

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i <= (n); i++)
#define show(a, n) rep(i,n) {cout<<a[i]<<' ';} cout<<endl
#define show2(a, n, m) rep(i, n) { rep(j, m) {cout << a[i][j] << ' ';} cout << endl;} 
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<long long, long long> pll;
typedef long double ld;

const int INF = 1 << 30;
const long long INFL = 1LL << 60;
const int MOD = 1000000007;
const int MAX = 100000;
const int N = 100010;

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
int main() {
//	cout << fixed << setprecision(15);
    string k;
    int d;
    cin >> k >> d;
    vector<vvm> dp(k.size() + 1, vvm(2, vm(d))); // digit, smaller, remainder
    dp[0][0][0] = 1;
    rep(i, k.size()) rep(j, 2) rep(l, d) {
        int c = k[i] - '0';
        for(int m = 0; m <= (j ? 9 : c); m++) {
            dp[i + 1][j || (m < c)][(l + m) % d] += dp[i][j][l];
        }
    }
    mint ans = dp[k.size()][1][0] + dp[k.size()][0][0];
    ans -= 1;
    cout << ans.x << endl;
}
