#define _CRT_SECURE_NO_WARNINGS
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#define rep(i, n) for(int i=0;i<(n);i++)
#define REP(i, n) for(int i=1;i<=(n);i++)
#define all(V) V.begin(),V.end()
typedef long long lint;
typedef std::pair<lint, lint> P;
constexpr int INF = INT_MAX / 10;
constexpr lint LINF = LLONG_MAX / 10;
constexpr double eps = 1e-9;
template<class T>
class prique :public std::priority_queue<T, std::vector<T>, std::greater<T>> {};
template <class T, class U>
inline bool chmax(T& lhs, const U& rhs) {
	if (lhs < rhs) {
		lhs = rhs;
		return 1;
	}
	return 0;
}
template <class T, class U>
inline bool chmin(T& lhs, const U& rhs) {
	if (lhs > rhs) {
		lhs = rhs;
		return 1;
	}
	return 0;
}
inline lint gcd(lint a, lint b) {
	while (b) {
		lint c = a;
		a = b; b = c % b;
	}
	return a;
}
inline lint lcm(lint a, lint b) {
	return a / gcd(a, b) * b;
}
bool isprime(lint n) {
	if (n == 1)return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0)return false;
	}
	return true;
}
lint mypow(lint a, lint b) {
	if (!b)return 1;
	if (b & 1)return mypow(a, b - 1) * a;
	lint memo = mypow(a, b >> 1);
	return memo * memo;
}
lint modpow(lint a, lint b, lint m) {
	if (!b)return 1;
	if (b & 1)return modpow(a, b - 1, m) * a % m;
	lint memo = modpow(a, b >> 1, m);
	return memo * memo % m;
}
void printArray(std::vector<int>& vec) {
	rep(i, vec.size() - 1)std::cout << vec[i] << " ";
	std::cout << vec.back() << std::endl;
}
template<typename T>
void printArray(T l, T r) {
	T rprev = r;
	rprev--;
	for (T i = l; i != rprev; i++) {
		std::cout << *i << " ";
	}
	std::cout << *rprev << std::endl;
}
std::string to_string(std::vector<int>& vec) {
	std::string res = "[";
	rep(i, vec.size() - 1)res += std::to_string(vec[i]) + ", ";
	res += std::to_string(vec.back()) + "]";
	return res;
}
int n, a[200010], b[200010][2], c[200010][2];
lint dp[200010][2][2];
signed main() {
	std::cin >> n;
	rep(i, n)std::cin >> a[i];
	rep(i, n) {
		if (n % 2) {
			b[i][0] = i / 2; c[i][0] = (i + 1) / 2;
			b[i][1] = (i + 1) / 2; c[i][1] = i / 2 + 1;
			if (i == 0)b[i][1] = 1;
			if (i == n - 1)c[i][1] = n / 2;
		}
		else {
			b[i][0] = c[i][0] = (i + 1) / 2;
			b[i][1] = c[i][1] = i / 2 + 1;
		}
	}
	rep(i, n) {
		rep(j, 2) {
			rep(k, 2)dp[i][j][k] = -LINF;
		}
	}
	dp[0][0][0] = 0;
	dp[0][1][0] = a[0];
	REP(i, n - 1) {
		//use
		if (b[i - 1][0] + 1 == b[i][1])chmax(dp[i][1][0], dp[i - 1][0][0] + a[i]);
		if (b[i - 1][0] + 2 == b[i][1])chmax(dp[i][1][0], dp[i - 1][0][1] + a[i]);
		if (b[i][1] != c[i][1] && b[i - 1][0] + 1 == b[i][1] + 1)chmax(dp[i][1][1], dp[i - 1][0][0] + a[i]);
		if (b[i][1] != c[i][1] && b[i - 1][0] + 2 == b[i][1] + 1)chmax(dp[i][1][1], dp[i - 1][0][1] + a[i]);
		//not
		if (b[i - 1][0] == b[i][0])chmax(dp[i][0][0], dp[i - 1][0][0]);
		if (b[i - 1][0] + 1 == b[i][0])chmax(dp[i][0][0], dp[i - 1][0][1]);
		if (b[i][0] != c[i][0] && b[i - 1][0] == b[i][0] + 1)chmax(dp[i][0][1], dp[i - 1][0][0]);
		if (b[i][0] != c[i][0] && b[i - 1][0] + 1 == b[i][0] + 1)chmax(dp[i][0][1], dp[i - 1][0][1]);
		if (b[i - 1][1] == b[i][0])chmax(dp[i][0][0], dp[i - 1][1][0]);
		if (b[i - 1][1] + 1 == b[i][0])chmax(dp[i][0][0], dp[i - 1][1][1]);
		if (b[i][0] != c[i][0] && b[i - 1][1] == b[i][0] + 1)chmax(dp[i][0][1], dp[i - 1][1][0]);
		if (b[i][0] != c[i][0] && b[i - 1][1] + 1 == b[i][0] + 1)chmax(dp[i][0][1], dp[i - 1][1][1]);
	}
	lint ans = -LINF;
	rep(i, 2) {
		rep(j, 2)chmax(ans, dp[n - 1][i][j]);
	}
	std::cout << ans << std::endl;
	return 0;
}