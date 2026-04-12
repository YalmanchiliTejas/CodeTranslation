#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tl3;

//typedef modint998244353 mint;

const int BIG_NUM = 1e9;
const ll INF = 1000000000000000000;
const ll MOD = 1e9 + 7;
//const ll MOD = 998244353;

const ll MAX = 1e9 + 5;


int main() {
	int n;
	cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	


	ll cnt = 0;
	while (a[n - 1] >= n) {
		ll c = 0;
		vector<ll> b(n);
		for (int i = 0; i < n; i++) {
			c += a[i] / n;
			b[i] = a[i] / n;
			a[i] %= n;
			cnt += b[i];
		}

		for (int i = 0; i < n; i++) {
			a[i] += c - b[i];
		}

		sort(a.begin(), a.end());
	}
	cout << cnt << endl;
}