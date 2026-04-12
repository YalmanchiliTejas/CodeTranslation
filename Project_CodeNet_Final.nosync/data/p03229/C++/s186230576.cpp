#include <bits/stdc++.h>
#define int long long
#define mod (int)(1e9+7)
#define inf (int)(3e18)
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define P std::pair<int,int>
#define PiP std::pair<int,std::pair<int,int>>
#define all(v) v.begin(),v.end()
#define mkp std::make_pair
#define prique(T) std::priority_queue<T,vector<T>,greater<T>>
using namespace std;
template<class T> inline void chmax(T& a, T b) { a = std::max(a, b); }
template<class T> inline void chmin(T& a, T b) { a = std::min(a, b); }

bool prime(int x) {
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0)return false;
	}
	return x != 1;
}
int gcd(int x, int y) {
	if (y == 0)return x;
	return gcd(y, x % y);
}
int lcm(int x, int y) {
	return x / gcd(x, y) * y;
}
int kai(int x, int y) {
	int res = 1;
	for (int i = x - y + 1; i <= x; i++) {
		res *= i; res %= mod;
	}
	return res;
}
int mod_pow(int x, int y, int m) {
	int res = 1;
	while (y > 0) {
		if (y & 1) {
			res = res * x % m;
		}
		x = x * x % m;
		y >>= 1;
	}
	return res;
}
int comb(int x, int y) {
	if (y > x)return 0;
	return kai(x, y) * mod_pow(kai(y, y), mod - 2, mod) % mod;
}
int get_rand(int MIN, int MAX) {
	std::random_device rnd;
	std::mt19937_64 mt64(rnd());
	std::uniform_int_distribution<int>engine(MIN, MAX);
	return engine(mt64);
}
/*--------Library Zone!--------*/

int n, a[114514], ans;
signed main() {
	cin >> n;
	rep(i, n)cin >> a[i];
	sort(a, a + n);
	if (n % 2) {
		int last = a[n / 2];
		rep(i, n - 1) {
			if (i % 2 == 0) {
				ans += last - a[i / 2];
				last = a[i / 2];
			}
			else {
				ans += a[n - 1 - i / 2] - last;
				last = a[n - 1 - i / 2];
			}
		}
		int ans2 = 0;
		last = a[n / 2];
		rep(i, n - 1) {
			if (i % 2 == 0) {
				ans2 += a[n - 1 - i / 2] - last;
				last = a[n - 1 - i / 2];
			}
			else {
				ans2 += last - a[i / 2];
				last = a[i / 2];
			}
		}
		cout << max(ans, ans2) << endl;
	}
	else {
		int ans2 = 0;
		int last = a[n / 2];
		rep(i, n - 1) {
			if (i % 2 == 0) {
				ans += last - a[i / 2];
				last = a[i / 2];
			}
			else {
				ans += a[n -1- i / 2] - last;
				last = a[n -1- i / 2];
			}
		}
		last = a[n / 2 - 1];
		rep(i, n - 1) {
			if (i % 2 == 0) {
				ans2 += a[n - 1 - i / 2] - last;
				last = a[n - 1 - i / 2];
			}
			else {
				ans2 += last - a[n / 2];
				last = a[n / 2];
			}
		}
		cout << max(ans, ans2) << endl;
	}
}
