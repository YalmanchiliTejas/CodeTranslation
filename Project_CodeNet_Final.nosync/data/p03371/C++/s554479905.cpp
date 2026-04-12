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

#define PB push_back
#define ALL(a)  (a).begin(),(a).end()
#define DWN(a)  (a).begin(),(a).end(), greater<int>()
#define rep(i, m) for (int i = 0; i < m; i++)
#define REP(i, n, m) for (int i = n; i < m; i++)

#define mod 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
const int INF = (int)1e9;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	ll ans = INF;
	for (int i = 0; i <= 100000; i++) {
		ll cost = max(0, x - i) * a + max(0, y - i) * b + i * 2 * c;
		ans = min(ans, cost);
	}
	cout << ans << "\n";
	return 0;
}