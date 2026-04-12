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
#define DEBUG 0
const ld infl = 1e100;
const ll mod = 998244353;
const ld eps = 1e-9;
const ll inf = 1e15;
const int dx[] = { 1,0,-1,0,0 };
const int dy[] = { 0,1,0,-1,0 };
ll base_mod = 1420622537;

ll fact[10000010];
ll inv_fact[10000010];
ll pow2[10000010];

ll inv(ll x) {
	// x^(mod-2)
	ll b = mod - 2;
	ll res = 1;
	while (b) {
		if (b & 1)	res = (res * x) % mod;
		x = (x * x) % mod;
		b /= 2;
	}
	return res;
}

int main() {
	int n;	cin >> n;
	fact[0] = inv_fact[0] = pow2[0] = 1;
	SREP(i, 1, n) {
		fact[i] = (fact[i - 1] * i) % mod;
		inv_fact[i] = (inv_fact[i - 1] * inv(i)) % mod;
		pow2[i] = (pow2[i - 1] * 2) % mod;
	}
	ll res = 1;
	rep(i, n)	res = (res * 3) % mod;
	ll sub = 0;
	SREP(i, (n + 2) / 2, n) {
		// nCi
		ll nCi = (fact[n] * ((inv_fact[i] * inv_fact[n - i]) % mod)) % mod;
		ll select = (nCi * pow2[n - i]) % mod;
		sub = (sub + select) % mod;
	}
	cout << (res + 2 * mod - 2 * sub) % mod << endl;
	return 0;
}