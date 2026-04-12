#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <string>
#include <vector>
#include <utility>
#include <complex>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <deque>
#include <tuple>
#include <bitset>
#include <limits>
#include <algorithm>
#include <array>
#include <random>
#include <complex>
#include <regex>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef complex<ld> compd;
#define quickIO()	{cin.tie(0);	cout.sync_with_stdio(false);}
#define reach(i,a)	for(auto i:a)
#define rep(i,n)	for(int i=0;i<((int)n);i++)
#define REP(i,n)	for(int i=0;i<=((int)n);i++)
#define srep(i,a,n)	for(int i=a;i<((int)n);i++)
#define SREP(i,a,n)	for(int i=a;i<=((int)n);i++)
#define rrep(i,n)	for(int i=n-1;i>=0;i--)
#define RREP(i,n)	for(int i=n;i>=0;i--)
#define all(a)	(a).begin(),(a).end()
#define mp(a,b)	make_pair(a,b)
#define mt	make_tuple
#define pb	push_back
template<typename T> istream& operator >> (istream& is, vector<T>& vec) {
	for (T& x : vec)	is >> x;
	return is;
}
template<typename T> ostream& operator << (ostream& os, vector<T>& vec) {
	os << "[";
	rep(i, vec.size())	os << (i ? ", " : "") << vec[i];
	os << "]";
	return os;
}
template<typename T> ostream& operator << (ostream& os, set<T>& s) {
	os << "{";
	for (T x : s)	os << x << ", ";
	os << "}";
	return os;
}
template<typename T> istream& operator >> (istream& is, pair<T, T>& p) {
	is >> p.first >> p.second;
	return is;
}
template<typename T> ostream& operator << (ostream& os, pair<T, T>& p) {
	os << p.first << " " << p.second;
	return os;
}
template<typename T> bool operator < (vector<T>& a, vector<T>& b) {
	rep(i, a.size()) {
		if (i == b.size())	return false;
		if (a[i] < b[i])	return true;
		else if (a[i] > b[i])	return false;
	}
	return false;
}
template<typename T> bool operator > (vector<T>& a, vector<T>& b) {
	rep(i, a.size()) {
		if (i == b.size())	return true;
		if (a[i] < b[i])	return false;
		else if (a[i] > b[i])	return true;
	}
	return false;
}
int bitcnt(ll x) {
	x = ((x & 0xAAAAAAAAAAAAAAAA) >> 1) + (x & 0x5555555555555555);
	x = ((x & 0xCCCCCCCCCCCCCCCC) >> 2) + (x & 0x3333333333333333);
	x = ((x & 0xF0F0F0F0F0F0F0F0) >> 4) + (x & 0x0F0F0F0F0F0F0F0F);
	x = ((x & 0xFF00FF00FF00FF00) >> 8) + (x & 0x00FF00FF00FF00FF);
	x = ((x & 0xFFFF0000FFFF0000) >> 16) + (x & 0x0000FFFF0000FFFF);
	x = ((x & 0xFFFFFFFF00000000) >> 32) + (x & 0x00000000FFFFFFFF);
	return x;
}
int bitcnt(int x) {
	x = ((x & 0xAAAAAAAA) >> 1) + (x & 0x55555555);
	x = ((x & 0xCCCCCCCC) >> 2) + (x & 0x33333333);
	x = ((x & 0xF0F0F0F0) >> 4) + (x & 0x0F0F0F0F);
	x = ((x & 0xFF00FF00) >> 8) + (x & 0x00FF00FF);
	x = ((x & 0xFFFF0000) >> 16) + (x & 0x0000FFFF);
	return x;
}
ll sqrtll(ll x) {
	ll left = 0, right = x;
	rep(i, 100) {
		ll mid = (left + right) >> 1;
		if (mid * mid <= x)	left = mid;
		else	right = mid;
	}
	return left;
}
ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a % b);
}
#define debug(x)	printf("Case #%d: ", x)
#undef DEBUG
const ld infl = 1e100;
const ll mod = 1e9 + 7;
const ld eps = 1e-9;
const ll inf = 1e15;
const int dx[] = { 1,0,-1,0,1, -1 };
const int dy[] = { 0,1,0,-1,1, -1 };

int main() {
	int n;	cin >> n;
	vll a(n);	cin >> a;
	if (n % 2 == 0) {
		ll sum = 0;
		for (int i = 1; i < n; i += 2)	sum += a[i];
		ll res = sum;
		srep(i, 1, n) {
			if (i & 1)	sum += a[i - 1] - a[i];
			res = max(res, sum);
		}
		cout << res << endl;
	}
	else {
		vector<vll> dp(3, vll(n));
		dp[0][0] = a[0];
		for (int i = 3; i < n; i += 2) {
			dp[0][i - 1] = dp[0][i - 3] + a[i - 1];
		}
		dp[1][1] = a[1];
		for (int i = 3; i < n; i++) {
			dp[1][i] = max(
				dp[0][i - 3] + a[i],
				dp[1][i - 2] + a[i]
			);
		}
		dp[2][2] = a[2];
		for (int i = 4; i < n; i++) {
			dp[2][i] = max(
				dp[1][i - 3] + a[i],
				dp[2][i - 2] + a[i]
			);
		}
		cout << max(dp[2][n - 1], max(dp[1][n - 2], dp[0][n - 3])) << endl;
	}
}