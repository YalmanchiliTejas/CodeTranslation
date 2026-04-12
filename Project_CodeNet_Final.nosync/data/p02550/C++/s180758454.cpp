#include <bits/stdc++.h>
using namespace std;


#define int long long 


const int N = 2e5 + 7;

int nxt[N], vis[N];

int32_t main() {
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, x, m; cin >> n >> x >> m;
	int y = x;
	memset(nxt, -1, sizeof nxt);
	while(nxt[y] == -1) {
		//cout << y << endl;
		nxt[y] = y * y % m;
		y = y * y % m;
	}
	vector <int> a, b;
	int z = x;
	while(z != y) {
		a.push_back(z);
		z = z * z % m;
	}
	int csum = 0;
	while(!vis[y]) {
		csum += y;
		b.push_back(y);
		vis[y] = 1;
		y = y * y % m;
	}

	int ans = 0;

	for(int i = 1; i <= n && i <= a.size(); ++i) ans += a[i - 1];

	n -= (int)a.size();

	ans += (n / (int)b.size()) * csum;

	n %= (int)b.size();

	for(int i = 1; i <= n; i++) ans += b[i - 1];

	cout << ans << endl;


}
