#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<algorithm>
#include<map>
#include<set>
#include<cstdlib>
#include<cmath>
#include<numeric>
#include<iomanip>
#include<functional>
#include<cstdlib>
#include<queue>
#include<deque>
#include <iterator>     // std::back_inserter
const double PI = acos(-1);
using namespace std;
using ll =long long;
#define rep(i,n)for(ll i=0;i<(n);i++)
const int mod = 1000000007;
const ll inf = 1e18 + 1;
int ctoi(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	return 0;
}

ll gcd(ll a, ll b) {
	if (a % b == 0) {
		return b;
	}
	else {
		return gcd(b, a % b);
	}
}
ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
};
//fixed << setprecision(2)
template<class T> inline bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<class T> inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

/*コンビネーション*/

//ll f[101010], rf[101010];
//ll inv(ll x) {
//	ll res = 1;
//	ll k = mod - 2;
//	ll y = x;
//	while (k) {
//		if (k & 1) res = (res * y) % mod;
//		y = (y * y) % mod;
//		k /= 2;
//	}
//	return res;
//}
//void init() {
//	f[0] = 1;
//	for (ll i = 1; i < 101010;i++) f[i] = (f[i - 1] * i) % mod;
//	for(ll i = 0; i < 101010; i++) rf[i] = inv(f[i]);
//}
////---------------------------------------------------------------------------------------------------
//ll C(int n, int k) {
//	ll a = f[n]; // = n!
//	ll b = rf[n - k]; // = (n-k)!
//	ll c = rf[k]; // = k!
//
//	ll bc = (b * c) % mod;
//
//	return (a * bc) % mod;
//}

/*コンビネーション*/

/*Union Find*/
#define MAX_N 200000
#define MAX_M 200000
vector<ll>par(MAX_N);
vector<ll>ran(MAX_N);
void init(ll N) {
	rep(i, N) {
		par[i] = i;
		ran[i] = 0;
	}
}
ll find(ll x) {
	if (par[x] == x) {
		return x;
	}
	else {
		return par[x] = find(par[x]);
	}
}
//xとyの属する集合を併合
void unite(ll x,ll y) {
	x = find(x);
	y = find(y);
	if (x == y)return;
	if (ran[x] < ran[y]) {
		par[x] = y;

	}
	else {
		par[y] = x;
		if (ran[x] == ran[y])ran[x]++;
	}
}
bool same(ll x, ll y) {
	return find(x) == find(y);
}
/*Union Find*/
//小文字=大文字+32
int main() {
	ll N; cin >> N;
	vector<ll>H(N);
	rep(i, N) {
		cin >> H[i];
	}
	int m = 0;
	int res=0;
	rep(i, N) {
		if (H[i] >= m) {
			m = H[i];
			res++;
		}
	}
	cout << res;

}