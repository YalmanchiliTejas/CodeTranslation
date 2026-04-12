#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <list>
#include <stack>
#include <string>
#include <functional>
#include <numeric>
#define _USE_MATH_DEFINES
#include <math.h>
#include <iomanip>
#include <map>
#include <set>
#include <cstdlib>
#include <bitset>
using namespace std;
#define INT_MAX 2147483647
#define INT_MIN (-2147483647 - 1)
#define INF (int)1e8
#define _INF (int)-1e8
#define INFLL (long long)1e14
#define _INFLL (long long)-1e14
#define Loop(i, n) for(int i = 0; i < (int)n; i++)
#define Loop1(i, n) for(int i = 1; i <= (int)n; i++)
#define Loopr(i, n) for(int i = (int)n - 1; i >= 0; i--)
#define Loopr1(i, n) for(int i = (int)n; i >= 1; i--)
#define bitmanip(m,val) static_cast<bitset<(int)m>>(val)
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef pair<int, int> P;

class Euclid {
private:
	ll m, n;
	vvll mx_multiply(vvll mx1, vvll mx2) {
		vvll ret(mx1.size(), vll(mx2[0].size(), 0));
		Loop(i, mx1.size()) {
			Loop(j, mx1[0].size()) {
				Loop(k, mx2[0].size()) {
					ret[i][j] += mx1[i][k] * mx2[k][j];
				}
			}
		}
		return ret;
	}
public:
	ll x, y, gcd;
	Euclid(ll M, ll N) {
		m = M;
		n = N;
	}
	//mx+ny=gcd(m,n)であるx,yを求める
	void mainfunc() {
		vll r(100), k(100);
		bool swapflag = false, mflag = false, nflag = false;
		if (m < n) { swap(m, n); swapflag = true; }
		if (m < 0) { m *= -1; mflag = true; }
		if (n < 0) { n *= -1; nflag = true; }
		r[0] = m;
		r[1] = n;
		int h = 1;
		while (1) {
			k[h - 1] = r[h - 1] / r[h];
			r[h + 1] = r[h - 1] % r[h];
			if (r[h + 1] == 0) break;
			h++;
		}
		gcd = r[h];
		vvll mx(2, vll(2, 1));
		mx[0][0] = 0;
		mx[1][1] = (-1) * k[0];
		Loop1(i, h - 1) {
			vvll multiplier(2, vll(2, 1));
			multiplier[0][0] = 0;
			multiplier[1][1] = (-1) * k[i];
			mx = mx_multiply(multiplier, mx);
		}
		x = mx[0][0];
		y = mx[0][1];
		if (nflag) { n *= -1; y *= -1; }
		if (mflag) { m *= -1; x *= -1; }
		if (swapflag) { swap(m, n); swap(x, y); }
	}
};

//x! O(x)
vll mod_factorial(ll x, ll mod) {
	if (x < 0) return{};
	else {
		vll ret((int)x + 1);
		ret[0] = 1;
		Loop1(i, (int)x) ret[i] = ret[i - 1] * i % mod;
		return ret;
	}
}

//x^y
ll mod_pow(ll x, ll y, ll mod) {
	if (y == 1) return x;
	else {
		ll ans = mod_pow(x, y / 2, mod);
		ans = ans * ans % mod;
		if (y % 2 == 1) ans = ans * x % mod;
		return ans;
	}
}

//≡1/x
ll mod_reciprocal(ll x, ll mod) {
	Euclid *euclid = new Euclid(x, mod * (-1));
	euclid->mainfunc();
	ll ret = euclid->x;
	if (ret < 0) ret += (ret / mod*(-1) + 1) * mod;
	return ret;
}


int main() {
	ll n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;
	//dp[i][j] = i人以下のグループのみで、j人使っている場合の数
	vll dp(n + 1, 0), dp2(n + 1, 0);
	dp[0] = 1;
	ll mod = 1e9 + 7;
	vll fact = mod_factorial(n, mod);
	vll recfact(n + 1);
	Loop(i, n + 1) {
		recfact[i] = mod_reciprocal(fact[i], mod);
	}
	Loop1(i, b) {
		dp2[0] = dp[0];
		if (i < a) continue;
		Loop1(j, n) {
			dp2[j] = dp[j];
			for (int k = c; k <= d; k++) {
				ll l = j - i * k;
				if (l < 0) break;
				ll q = dp[l] * fact[n - l] % mod;
				q = q * recfact[n - j] % mod;
				q = q * mod_pow(recfact[i], k, mod) % mod;
				q = q * recfact[k] % mod;
				dp2[j] = (dp2[j] + q) % mod;
			}
		}
		dp = dp2;
	}
	cout << dp[n] << endl;
	return 0;
}