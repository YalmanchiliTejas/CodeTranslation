#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<functional>
#include<algorithm>
#include<stdlib.h>
#include<string>
#include<string.h>
#define _USE_MATH_DEFINES
#include<math.h>
#include<deque>
#include<set>
#include<map>
#include<queue>
#include<list>
#include<iostream>
#include <bitset>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(auto i=a;i<b;i++)
#define all(_x) _x.begin(), _x.end()
#define r_sort(_x) sort(_x.begin(), _x.end(), std::greater<int>())
#define vec_cnt(_a, _n) (upper_bound(all(_a), _n) - lower_bound(all(_a), _n))
#define vec_unique(_a) _a.erase(std::unique(all(_a)), _a.end());
#define vvec vector<vector<ll>>
ll gcd(ll a, ll b) { return a % b == 0 ? b : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
#define INF 1 << 30
const int mod = 1000000007;
ll power(ll x, ll p) { ll a = 1; while (p > 0) { if (p % 2 == 0) { x *= x; p /= 2; } else { a *= x; p--; } }return a; }
ll mpower(ll x, ll p) { ll a = 1; while (p > 0) { if (p % 2 == 0) { x = x * x % mod; p /= 2; } else { a = a * x % mod; p--; } }return a; }
ll c(ll n, ll k) { ll a = 1; rep(i, 1, k) { a *= n - i + 1; a /= i; }return a; }
ll mc(ll n, ll m) { ll k = 1, l = 1; rep(i, n - m + 1, n + 1) k = k * i % mod; rep(i, 1, m + 1) l = l * i % mod; l = mpower(l, mod - 2); return k * l % mod; }
ll p[50], x[50];
ll dfs(ll level, ll X) {
	if (X <= 1)return 0;
	else if (X < x[level - 1])return dfs(level - 1, X - 1);
	else if (X <= x[level - 1] + 1)return p[level - 1];
	else if (X == x[level - 1] + 2)return p[level - 1] + 1;
	else if (X < 2 * x[level - 1] + 1)return p[level - 1] + dfs(level - 1, X - x[level - 1] - 2) + 1;
	else return p[level - 1] * 2 + 1;
}
int main(void) {
	ll N, X;
	cin >> N >> X;
	p[0] = x[0] = 1;
	rep(i, 1, 50) {
		p[i] = p[i - 1] * 2 + 1;
		x[i] = x[i - 1] * 2 + 3;
	}
	printf("%lld\n", dfs(N, X));
	return 0;
}