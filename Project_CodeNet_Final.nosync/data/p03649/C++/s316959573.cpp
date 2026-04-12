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
#define fi first
#define se second
#define pb push_back
#define double long double
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, P> PP;
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
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	priority_queue<int> que;
	rep(i, n) que.push(a[i]);
	int ans = 0;
	while (ans < 100000) {
		int q = que.top(); que.pop();
		if (q + ans < n) {
			cout << ans << endl;
			return 0;
		}
		que.push(q - n - 1);
		ans++;
	}
	int sum = 0;
	rep(i, n) {
		cin >> a[i];
		sum += a[i];
	}
	vector<int> b(n);
	rep(i, n) b[i] = a[i] % (n + 1);
	int cnt = 0;
	rep(_, n + 1) {
		bool flag = true;
		int s = 0;
		rep(i, n) {
			if (b[i] == n) flag = false;
			s += b[i];
			b[i] = (b[i] + 1) % (n + 1);
		}
		if (flag) chmax(cnt, s);
	}
	bool check = false;
	sort(all(a)); reverse(all(a));
	if (a[0] >= n * n || a[1] >= n) check = true;
	if (check) cout << max(sum - cnt, 0LL) << endl;
}
