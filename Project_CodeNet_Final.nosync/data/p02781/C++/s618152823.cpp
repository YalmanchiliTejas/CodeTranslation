#include <bits/stdc++.h>
using namespace std;
#define x_ real()
#define y_ imag()
#define cross(a, b) (conj(a)*(b)).imag()
#define dot(a, b) (conj(a)*(b)).real()
#define PI acos(-1)
#define F first
#define S second
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL)
#define fileIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef complex<ld> point;
typedef tuple<int, int, int> line;
typedef vector<point> polygon;
typedef pair<double, double> pd;
pair<int, int> dirs[] = { {1, 2}, {-1, 2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, -2}, {-1, -2} };


string s;
int k;

ll dp[107][5][2];

ll solve(int idx, int count, bool good) {
	if (idx == s.size())
		return k == count;

	if (count > k)
		return 0;

	if (dp[idx][count][good] != -1)
		return dp[idx][count][good];

	ll ans = 0;
	if (good) {
		for (int i = 0; i < 10; i++) {
			ans += solve(idx+1, count + (i != 0), 1);
		}
	}
	else {
		for (int i = 0; i+'0' < s[idx]; i++) {
			ans += solve(idx+1, count + (i != 0), 1);
		}
		ans += solve(idx+1, count + (s[idx] != '0'), 0);
	}

	return dp[idx][count][good] = ans;

}


int main() {
	fastIO;
	memset(dp, -1, sizeof dp);
	cin >> s >> k;
	cout << solve(0, 0, 0);


}
