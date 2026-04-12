#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <string>
#include <tuple>
#include <random>
#include <map>
#include <queue>
#include <set>
#include <complex>
#include <algorithm>
#include <cassert>
#include <iterator>
#include <numeric>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;

const ll INF = 1e15;
const double eps = 1e-6;
const ll MOD = 1000000007;

int main() {
	ll A, B;
	cin >> A >> B;
	vector<vector<ll>> d(A+1, vector<ll>(B+1));
	for (int i = 1;i <= A;i++)
		for (int j = 1;j <= B;j++)
			cin >> d[i][j];
	vector<vector<ll>> e(101, vector<ll>(101, 0));
	for (ll a = 1;a <= A;a++)
		for (ll b = 1;b <= B;b++)
			for (ll ua = 0;ua <= 100;ua++)
				for (ll ub = 0;ub <= 100;ub++)
					e[ua][ub] = max(e[ua][ub], d[a][b] - (a * ua + b * ub));
	bool ok = true;
	for (ll a = 1;a <= A;a++)
		for (ll b = 1;b <= B;b++) {
			bool nowok = false;
			for (ll ua = 0;ua <= 100;ua++)
				for (ll ub = 0;ub <= 100;ub++)
					if (e[ua][ub] + a * ua + b * ub == d[a][b])
						nowok = true;
			ok &= nowok;
		}
	if (!ok)
		cout << "Impossible" << endl;
	else {
		ll cnt = 0;
		cout << "Possible" << endl;
		cout << "202 " << 101 * 101 + 100 + 100 << endl;
		for (int i = 1;i <= 100;i++) {
			cout << i << " " << i + 1 << " " << "X" << endl;
			cnt++;
		}
		for (int i = 102;i <= 201;i++) {
			cout << i << " " << i + 1 << " " << "Y" << endl;
			cnt++;
		}
		for (int ua = 0;ua <= 100;ua++)
			for (int ub = 0;ub <= 100;ub++) {
				cout << ua + 1 << " " << 202 - ub << " " << min(100LL, e[ua][ub]) << endl;
				cnt++;
			}
		cout << "1 202" << endl;

//		cout << cnt << endl;
	}
	return 0;
}
