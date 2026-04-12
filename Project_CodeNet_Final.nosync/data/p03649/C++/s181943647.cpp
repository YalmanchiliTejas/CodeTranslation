#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (ll(i) = (s); (i) > (e); (i)--)
#define debug(x) cout << #x << ": " << x << endl
#define mp make_pair
#define pb push_back
const ll MOD = 1000000007;
const int INF = 1e9;
const ll LINF = 1e16;
const double PI = acos(-1.0);
int dx[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/07/29  Problem: ARC 079 C / Link: http://arc079.contest.atcoder.jp/tasks/arc079_c  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */

ll N;
ll a[51];
ll ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	FOR(i, 0, N)cin >> a[i];
	
	FOR( x, 0,1000000) {
		FOR(i, 0, N) {
			if (a[i] >= N) {
				ll d = a[i] / N;
				ans += d;
				a[i] -= d*N;
				FOR(j, 0, N) {
					if (i != j)a[j] += d;
				}
			}
		}
	}
	
	
	
	
	cout << ans << endl;

	return 0;
}
