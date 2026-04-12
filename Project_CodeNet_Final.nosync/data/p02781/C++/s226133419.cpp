#include<iostream>
#include<algorithm>
#include <string>
#include <cstring>
#include<climits>
using namespace std;
typedef long long ll;

// i번째까지왔는데 0이아닌수를 j개 썼고 그때 값들이 n보다 크다면 1아니면 0 ㅋ
ll d[101][4][2];
int n, k;
string s;

ll go(int x, int y, int z) {
	if (x == n) {
		if (y == k)
			return 1;
		else return 0;
	}
	ll &ret = d[x][y][z];
	if (ret != -1)return ret;
	ret = 0;

	if (z == 0) {
		if (y < k) {
			ret += go(x + 1, y + 1, z) * (ll)9;
		}
		ret += go(x + 1, y, z);	
	}
	else {
		if (y < k) {
			for (int i = 1; i < (s[x] - '0'); i++) {
				ret += go(x + 1, y + 1, 0);
			}
		}
		if (s[x] != '0') {
			ret += go(x + 1, y, 0);
			if (y < k)
				ret += go(x + 1, y + 1, 1);
		}
		else {
			ret += go(x + 1, y, 1);
		}
	}
	return ret;
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> s >> k;
	n = s.size();
	memset(d, -1, sizeof(d));
	ll ans = 0;

	for (int i = 0; i < (s[0] - '0'); i++) {
		if (i == 0) {
			ans += go(1, 0, 0);
		}
		else {
			ans += go(1, 1, 0);
		}
	}
	if ((s[0] - '0') != 0) {
		ans += go(1, 1, 1);
	}
	else ans += go(1, 0, 1);

	cout << ans << '\n';
}