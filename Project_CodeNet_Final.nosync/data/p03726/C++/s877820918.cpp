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
#include <complex>
#include <time.h>
#define int long long
#define endl '\n'
#define INF 1000000000000000000
#define EPS 1e-10
#define PI 3.141592653589793238
#define all(a) a.begin(),a.end()
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pb push_back
#define double long double
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<P, ll> PP;
typedef complex<double> com;
template<class T, class S> bool chmax(T &a, const S &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T, class S> bool chmin(T &a, const S &b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll n, ll m) { return (m ? gcd(m, n%m) : n); }
ll lcm(ll n, ll m) { return n / gcd(n, m)*m; }


signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);
	//modcalc();

	int n;
	cin >> n;
	vector<vector<int>> graph(n, vector<int>());
	vector<int> deg(n);
	vector<int> a(n - 1), b(n - 1);
	rep(i, n - 1) {
		cin >> a[i] >> b[i];
		a[i]--; b[i]--;
		graph[a[i]].pb(b[i]);
		graph[b[i]].pb(a[i]);
		deg[a[i]]++;
		deg[b[i]]++;
	}
	int cnt = 0;
	queue<int> que;
	rep(i, n) if (deg[i] == 1) que.push(i);
	while (!que.empty()) {
		int p = que.front(); que.pop();
		if (deg[p] != 1) continue;
		int q = -1;
		for (int i : graph[p]) {
			if (deg[i]) q = i;
		}
		if (q != -1) cnt++;
		else {
			cout << "First" << endl;
			return 0;
		}
		deg[p] = 0; deg[q] = 0;
		for (int i : graph[q]) {
			if (i == p || !deg[i]) continue;
			deg[i]--;
			if (deg[i] == 1) {
				que.push(i);
			}
		}
	}
	cout << (cnt * 2 != n ? "First" : "Second") << endl;
}