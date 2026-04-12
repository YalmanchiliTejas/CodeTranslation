#define _USE_MATH_DEFINES
#include<iostream>
#include<string>
#include<queue>
#include<cmath>
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
#include<climits>
#include<fstream>
using namespace std;
///////////////////library zone!!!!!!!!!!!!!!!!!!!!!!!!!!!!
typedef long long ll;
typedef long double ld;
#define all(a) (a).begin(),(a).end()
#define EPS (1e-5)
#define bit(n,k) ((n>>k)&1)
const ll Mod = 1000000007;
const ll mod = 998244353;
struct H {
	ll x, y;
	bool operator<(const H& b) const {
		if (x != b.x) return x < b.x;
		return y < b.y;
	}
	bool operator>(const H & b) const {
		if (x != b.x) return x > b.x;
		return y > b.y;
	}
	bool operator==(const H & b) const { return x == b.x && y == b.y; }
	bool operator!=(const H & b) const { return (*this) != b; }
};
struct P {
	ll pos, cost;
	bool operator<(const P& b) const { return cost < b.cost; }
	bool operator>(const P& b) const { return cost > b.cost; }
};
struct B {
	ll to, cost;
};
struct E {
	ll from, to, cost;
	bool operator<(const E& b) const { return cost < b.cost; }
	bool operator>(const E& b) const { return cost > b.cost; }
};
template<typename T, typename U>
void chmin(T & a, U b) {
	if (a > b) a = b;
}
template<typename T, typename U>
void chmax(T & a, U b) {
	if (a < b) a = b;
}
template<typename T>
T max_0(T a) {
	if (a < 0) return 0;
	return a;
}
template<typename T>
T min_0(T a) {
	if (a > 0) return 0;
	return a;
}
ll read() {
	ll u;
	ll k = scanf("%lld", &u);
	return u;
}
ll gcd(ll i, ll j) {
	if (i > j) swap(i, j);
	if (i == 0) return j;
	return gcd(j % i, i);
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
int h, w;
bool a[100][100];
bool b[100][100];
signed main() {
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < w; j++) {
			if (s[j] == '#') a[i][j] = 1;
			else a[i][j] = 0;
		}
	}
	b[0][0] = 1;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (b[i][j]) {
				if (a[i + 1][j] && a[i][j + 1]) {
					cout << "Impossible\n";
					return 0;
				}
				if (a[i + 1][j]) {
					b[i + 1][j] = 1;
				}
				if (a[i][j + 1]) {
					b[i][j + 1] = 1;
				}
			}
			else if (a[i][j]) {
				cout << "Impossible\n";
				return 0;
			}
		}
	}
	cout << "Possible\n";
}