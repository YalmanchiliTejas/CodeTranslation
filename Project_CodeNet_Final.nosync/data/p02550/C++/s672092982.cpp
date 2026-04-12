#include <bits/stdc++.h>
using namespace std;

vector <long long> path;
int vis[100010];

int main () {
	memset(vis, -1, sizeof(vis));
	long long n, x, mod; cin >> n >> x >> mod;
	while (vis[x] == -1) {
		vis[x] = path.size();
		path.push_back(x);
		x = x * x % mod;
	}
	int pos = vis[x];
	long long ans = 0;
	int len = (int)path.size() - pos;
	long long k = (n - pos) / len, sum = 0;
	for (int i = 0; i < pos; i++) {
		ans += path[i], n--;
		if (n == 0) goto END;
	}
	for (int i = pos; i < path.size(); i++) {
		sum += path[i];
	}
	ans += k * sum, n %= len;
	for (int i = pos; i < pos + n; i++) {
		ans += path[i];
	}
	END:;
	cout << ans << endl;
	return 0;
}
