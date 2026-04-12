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
#include<climits>
#include<fstream>
using namespace std;
///////////////////library zone!!!!!!!!!!!!!!!!!!!!!!!!!!!!
typedef long long ll;
typedef long double ld;
#define all(a) (a).begin(),(a).end()
const ll Mod = 1000000007;
const ll mod = 998244353;
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
template<typename T, typename U>
void chmin(T &a, U b) {
	if (a > b) a = b;
}
template<typename T, typename U>
void chmax(T &a, U b) {
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
	scanf("%lld", &u);
	return u;
}
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
int n;
H a[200000];
int mi = Inf, ma = 0;
struct A {
	int x, y;
	bool operator<(const A &a) {
		int r = min(mi - a.x, a.y - ma);
		int k = min(mi - x, y - ma);
		return k < r;
	}
};
signed main() {
	cin >> n;
	int rmax = 0, rmin = Inf, bmax = 0, bmin = Inf;
	for (int i = 0; i < n; i++) {
		cin >> a[i].x >> a[i].y;
		if (a[i].x > a[i].y) swap(a[i].x, a[i].y);
		rmax = max(rmax, a[i].x);
		rmin = min(rmin, a[i].x);
		bmax = max(bmax, a[i].y);
		bmin = min(bmin, a[i].y);
	}
	int ans = (rmax - rmin)*(bmax - bmin);
	multiset<int>se;
	sort(a, a + n);
	reverse(a, a + n);
	for (int i = 0; i < n; i++) {
		se.insert(a[i].y);
	}
	for (int i = 0; i < n; i++) {
		se.erase(se.find(a[i].y));
		se.insert(a[i].x);
		ans = min(ans, (bmax - rmin)*(*prev(se.end()) - *(se.begin())));
	}
	cout << ans << endl;
}