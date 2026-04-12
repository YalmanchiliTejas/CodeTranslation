#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	int ans = inf;
	for (int i = 0; i <= 200000; i += 2) {
		int now = i * c;
		int res = i / 2;
		int tmpx = x - res, tmpy = y - res;
		now += max(0, tmpx) * a;
		now += max(0, tmpy) * b;
		ans = min(ans, now);
	}
	cout << ans << endl;
	return 0;
}
