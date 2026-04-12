#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <cassert>
#include <time.h>
#define INF 1000000009
#define LINF 1000000000000000009
#define all(a) a.begin(),a.end()
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, P> PP;
template<class T> bool chmax(T &a, const T&b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T&b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll n, ll m) { return (m ? gcd(m, n%m) : n); }
ll lcm(ll n, ll m) { return n / gcd(n, m)*m; }
ll mod = 1000000007;

int solve(string s, int k) {
	int ans = 0;
	int n = s.size();
	int c = s[0] - '0';
	if (k == 1) {
		if (n == 0) return 0;
		ans += 9 * (n - 1);
		ans += c;
		return ans;
	}
	if (k == 2) {
		if (n <= 1) return 0;
		ans += 81 * (n - 1)*(n - 2) / 2;
		ans += (c - 1)*(n - 1) * 9;
		int pl = n;
		for (int i = 1; i < n; i++) {
			if (s[i] != '0') {
				pl = i;
				break;
			}
		}
		string t = "";
		for (int i = pl; i < n; i++) t += s[i];
		ans += solve(t, 1);
		return ans;
	}
	if (k == 3) {
		if (n <= 2) return 0;
		ans += 729 * (n - 1)*(n - 2)*(n - 3) / 6;
		ans += (c - 1) * 81 * (n - 1)*(n - 2) / 2;
		int pl = n;
		for (int i = 1; i < n; i++) {
			if (s[i] != '0') {
				pl = i;
				break;
			}
		}
		string t = "";
		for (int i = pl; i < n; i++) t += s[i];
		ans += solve(t, 2);
		return ans;
	}
}

int main() {
	string s;
	int k;
	cin >> s >> k;
	cout << solve(s, k) << endl;
}
