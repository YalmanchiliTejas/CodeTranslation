#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define dup(x,y) (((x)+(y)-1)/(y))
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const double EPS = 1e-10;
const int INF = 1e9;
const ll LINF = 1e15;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

struct mint {
	ll x;
	mint(ll x=0):x((x%MOD+MOD)%MOD){}
	mint operator-() const { return mint(-x);}
	mint& operator+=(const mint a) {
	if ((x += a.x) >= MOD) x -= MOD;
		return *this;
	}
	mint& operator-=(const mint a) {
		if ((x += MOD-a.x) >= MOD) x -= MOD;
		return *this;
	}
	mint& operator*=(const mint a) { (x *= a.x) %= MOD; return *this;}
	mint operator+(const mint a) const { return mint(*this) += a;}
	mint operator-(const mint a) const { return mint(*this) -= a;}
	mint operator*(const mint a) const { return mint(*this) *= a;}
	mint pow(ll t) const {
		if (!t) return 1;
		mint a = pow(t>>1);
		a *= a;
		if (t&1) a *= *this;
		return a;
	}

	mint inv() const { return pow(MOD-2);}
	mint& operator/=(const mint a) { return *this *= a.inv();}
	mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

int main() {
	int n;
	cin >> n;
	vector<ll> a(n);
	rep(i,n) cin >> a[i];
	vector<mint> v(n+1, 0);
	rep(i,n) v[i+1] = v[i] + a[i];
	mint ans = 0;
	for (int i = 0; i < n-1; i++) {
		mint x = a[i];
		mint y = v[n] - v[i+1];
		mint t = x * y;
		ans += t;
	}
	cout << ans << endl;
}