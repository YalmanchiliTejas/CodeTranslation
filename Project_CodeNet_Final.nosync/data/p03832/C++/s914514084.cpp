#include<iostream>
#include<string>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#include<list>
#include<iomanip>
#include<vector>
#include<random>
#include<functional>
#include<algorithm>
#include<stack>
#include<cstdio>
#include<bitset>
#include<unordered_map>
#include <climits>
#include<fstream>
using namespace std;
///////////////////library zone!!!!!!!!!!!!!!!!!!!!!!!!!!!!
typedef long long ll;
typedef long double ld;
#define all(a) (a).begin(),(a).end()
const ll Mod = 1000000007;
struct P {
	ll pos, cost;
	bool operator<(const P &b) const { return cost < b.cost; }
	bool operator>(const P &b) const { return cost > b.cost; }
};
struct B {
	ll to, cost;
};
struct E {
	ll from, to, cost;
	bool operator<(const E &b) const { return cost < b.cost; }
	bool operator>(const E &b) const { return cost > b.cost; }
};
struct H {
	ll x, y;
	bool operator<(const H &b) const {
		if (x != b.x) return x < b.x;
		return y < b.y;
	}
	bool operator>(const H &b) const {
		if (x != b.x) return x > b.x;
		return y > b.y;
	}
	bool operator==(const H &b) const { return x == b.x&&y == b.y; }
	bool operator!=(const H &b) const { return (*this) != b; }
};
ll gcd(ll i, ll j) {
	if (i > j) swap(i, j);
	if (i == 0) return j;
	return gcd(j%i, i);
}
ll mod_pow(ll x, ll n, ll p) {
	ll res = 1;
	while (n > 0) {
		if (n & 1) res = res * x % p;
		x = x * x % p;
		n >>= 1;
	}
	return res;
}//x^n%p
const ll Inf = 3023372036854775807;
const int inf = 1500000000;
#define int long long
//----------------------------------------------------
int n, a, b, c, d;
int dp[2000];
//i人目までを入れて、今までの総和はj
int f[2000];
int g[2000];
int nCk(int n, int k) {
	return f[n] * g[k] % Mod * g[n - k] % Mod;
}
signed main() {
	cin >> n >> a >> b >> c >> d;
	dp[0] = 1;
	f[0] = 1;
	g[0] = 1;
	for (int i = 1; i < 2000; i++) {
		f[i] = f[i - 1] * i%Mod;
		g[i] = mod_pow(f[i], Mod - 2, Mod);
	}
	for (int i = a - 1; i < b; i++) {
		int t = i + 1;
		for (int j = n - 1; j >= 0; j--) {
			int k = c;
			for (int z = j + c * t; z <= n && z <= j + d * t; z += t) {
				int res = dp[j] * nCk(n - j, z - j) % Mod;
				res = res * f[z - j] % Mod;
				res = res * mod_pow(g[t], k, Mod) % Mod;
				res = res * g[k] % Mod;
				dp[z] += res;
				dp[z] %= Mod;
				k++;
			}
		}
	}
	cout << dp[n] << endl;
}