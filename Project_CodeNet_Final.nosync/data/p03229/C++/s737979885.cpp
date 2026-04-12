#include<iostream>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<functional>
#include<iomanip>
#include<queue>
#include<cassert>
#include<tuple>
#include<set>
#include<map>
#include<list>
#include<bitset>
#include<utility>
#include<numeric>

#define pb push_back
#define mp make_pair
#define all(a)  (a).begin(),(a).end()
#define dwn(a)  (a).begin(),(a).end(), greater<int>()
#define rep(i, m) for (int i = 0; i < m; i++)
#define REP(i, n, m) for (int i = n; i < m; i++)
#define V vector<int>
#define VV vector<V>
#define VVV vector<VV>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
const int INF = (int)1e9;
const ll inf = (ll)1e18;
const ll MOD{ (ll)1e9 + 7 };
const long double EPS = 1e-10;

int main() {
	int n;
	cin >> n;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	sort(a.begin(), a.end());
	vector<ll> b(n);
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			if (i == 0) {
				b[i] = 1;
			}
			else if (i == n - 1) {
				b[i] = 1;
			}
			else {
				b[i] = 2;
			}
		}
		else {
			if (i == 0) {
				b[i] = -1;
			}
			else if (i == n - 1) {
				b[i] = -1;
			}
			else {
				b[i] = -2;
			}
		}
	}
	ll ans1 = 0, ans2 = 0;
	sort(b.begin(), b.end());
	rep(i, n) {
		ans1 += a[i] * b[i];
	}
	rep(i, n) b[i] *= -1;
	reverse(b.begin(), b.end());
	rep(i, n) {
		ans2 += a[i] * b[i];
	}
	cout << max(ans1, ans2) << endl;
	return 0;
}