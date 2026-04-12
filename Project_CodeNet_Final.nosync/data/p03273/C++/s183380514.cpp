#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()

int main() {
#ifdef local
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	vector<string> vs(n);
	for(auto &s : vs) cin >> s;
	vector<int> r(n, 1), c(m, 1);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			r[i] &= vs[i][j] == '.';
			c[j] &= vs[i][j] == '.';
		}
	}
	for(int i = 0; i < n; i++) {
		if(r[i]) continue;
		for(int j = 0; j < m; j++) {
			if(c[j]) continue;
			cout << vs[i][j];
		}
		cout << '\n';
	}
	return 0;
}
