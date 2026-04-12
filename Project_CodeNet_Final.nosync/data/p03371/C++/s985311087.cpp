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
	for (int j = 0; j <= 200000; ++j) {
		if (j % 2 != 0) continue;
		int d = j * c;
		int na = j / 2, nb = j / 2;
		if (na < x) d += a * (x - na);
		if (nb < y) d += b * (y - nb);
		ans = min(ans, d);
	}
	cout << ans << endl;
	return 0;
}
