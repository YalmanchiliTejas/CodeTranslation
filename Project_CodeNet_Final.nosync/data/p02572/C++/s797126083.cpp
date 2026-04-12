#pragma comment(linker, "/STACK:128777216")
#pragma GCC optimize("fast-maths")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <bitset>
#include <stack>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <climits>
#include <ctime>
#include <random>
#include <complex>
using namespace std;

#define forx(_name, _from, _to, _value) for (int _name = _from; _name < _to; _name += _value)
#define rforx(_name, _from, _to, _value) for (int _name = _from; _name > _to; _name -= _value)
#define all(_STL_NAME) _STL_NAME.begin(), _STL_NAME.end()
#define rall(_STL_NAME) _STL_NAME.rbegin(), _STL_NAME.rend()
#define mp(_FIRST,_SECOND) make_pair(_FIRST, _SECOND)

typedef long long ll;
typedef unsigned long long llu;
typedef long double ld;
const ld eps = 1e-6;
mt19937 rndm;

void start() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(6); cout.setf(ios::fixed);
	string FILENAME = "\-_-/";
	rndm.seed(time(0));
#ifdef _DEBUG
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#else
	//freopen((FILENAME + ".in").c_str(), "rt", stdin);
	//freopen((FILENAME + ".out").c_str(), "wt", stdout);
#endif
}

int main() {
	/* File On */
	start();
	const int mod = 1000000007;
	int n;
	cin >> n;
	vector<ll> q(n);
	for (int i = 0; i < n; ++i)
		cin >> q[i];
	vector<ll> suf(n + 1);
	for (int i = n - 1; i >= 0; --i) {
		suf[i] = (suf[i + 1] + q[i]) % mod;
	}
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		ans = (ans + q[i] * suf[i + 1] % mod) % mod;
	}
	cout << ans;
#ifdef _DEBUG
	cout << "\nTime: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}