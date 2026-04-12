#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>
#include <iomanip>

using namespace std;

#define REP(i, n) for(ll i = 0;i < n;i++)
#define REPR(i, n) for(ll i = n;i >= 0;i--)
#define FOR(i, m, n) for(ll i = m;i < n;i++)
#define FORR(i, m, n) for(ll i = m;i >= n;i--)
#define REPO(i, n) for(ll i = 1;i <= n;i++)
#define ll long long
#define INF (ll)1 << 60
#define MINF (-1 * INF)
#define ALL(n) n.begin(),n.end()
#define MOD 1000000007
#define P pair<ll, ll>


ll n, s[310000], a, b;
int main() {
	cin >> n;
	REP(i, n) {
		cin >> s[i];
	}
	a = 0, b = n - 1;
	REP(i, n) {
		if (a < i) {
			cout << "no" << endl;
			return 0;
		}
		a = max(a, i + s[i] / 10);
	}
	REPR(i, n - 1) {
		if (b > i) {
			cout << "no" << endl;
			return 0;
		}
		b = min(b, i - s[i] / 10);
	}
	cout << "yes" << endl;
}
