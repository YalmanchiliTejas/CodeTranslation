#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define inf 1000000007
typedef pair<int, int> P;

bool prime(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0)return false;
	}
	return n != 1;
}
int gcd(int x, int y) {
	if (y == 0)return x;
	return gcd(y, x % y);
}
int lcm(int x, int y) {
	return x / gcd(x, y) * y;
}

int n, m, ans = 0;
vector<int>go[19];
bool a[19];

void dfs(int now, int cnt) {
	//cout << now << " " << cnt << endl;
	if (cnt == n) {
		ans++;
		return;
	}
	cnt++;
	a[now] = false;
	rep(i, go[now].size()) {
		if (a[go[now][i]]) {
			dfs(go[now][i], cnt);
		}
	}
	a[now] = true;
	return;
}

signed main() {
	cin >> n >> m;
	rep(i, m) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		go[x].push_back(y);
		go[y].push_back(x);
	}
	rep(i, n) a[i] = true;
	dfs(0, 1);
	cout << ans << endl;

	return 0;
}
