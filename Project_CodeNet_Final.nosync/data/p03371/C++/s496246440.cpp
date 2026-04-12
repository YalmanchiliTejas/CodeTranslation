#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define maxs(a, b) a = max(a, b)
#define mins(a, b) a = min(a, b)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll linf = (1ll << 61);
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	int ans = inf;
	for (int i = 0; i <= 300000; ++i) {
		int tmp_c = i;
		int tmp_cost = i * c;
		int tmp_a = max(0, x - tmp_c / 2);
		int tmp_b = max(0, y - tmp_c / 2);
		int add_cost = tmp_a * a + tmp_b * b;
		mins(ans, tmp_cost + add_cost);
	}
	printf("%d\n", ans);
	return 0;
}
