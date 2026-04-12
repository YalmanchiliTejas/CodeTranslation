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
//const int MOD = 1000000007;
const int MAX = 100000;
const int N = 100010;

const ll MOD = 998244353; 

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

	// for prime mod
	mint inv() const { return pow(MOD-2);}
	mint& operator/=(const mint a) { return (*this) *= a.inv();}
	mint operator/(const mint a) const {mint res(*this); return res/=a;}
};

int main() {
//	cout << fixed << setprecision(15);
	int n, s;
	cin >> n >> s;
	vi a(n);
	rep(i, n) cin >> a[i];

	vector<vector<mint>> dp(n+1, vector<mint>(s+1));
	for(int i = 1; i <= n; i++) {
		int _a = a[i-1];
		dp[i][0] = 1;	// only A is in L-R but not selected
		if(_a <= s) dp[i][_a] = 1;	// only A is in L-R and selected
		rep(j, s+1) dp[i][j] += dp[i-1][j];	// Add A to L-R but not selected
		rep(j, s+1) if(j+_a <= s) dp[i][j+_a] += dp[i-1][j];	// Add A to L-R and selected
	}

	mint ans;
	rep(i, n+1) ans += dp[i][s];
	cout << ans.x << endl;
}
