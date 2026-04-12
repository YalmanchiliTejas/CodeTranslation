#include <bits/stdc++.h>
#define mod 1000000007
#define mod998 998244353
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define mkp make_pair
typedef long long ll;
using namespace std;
const string nyan("(=^・ω・^=)");

int N, M, Q, S, T, a, b, c, uf[4000], r[4000], d[4000][2][15];
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>q;
vector<pair<int, int>>v[4000];
ll e;

int t(int x) {
	if (uf[x] < 0)return x;
	return uf[x] = t(uf[x]);
}

bool u(int x, int y) {
	x = t(x);
	y = t(y);
	if (x == y)return false;
	if (uf[x] < uf[y]) {
		uf[x] += uf[y];
		uf[y] = x;
	}
	else {
		uf[y] += uf[x];
		uf[x] = y;
	}
	return true;
}

void dfs(int x) {
	for (auto p : v[x]) {
		if (!r[p.second]) {
			r[p.second] = r[x] + 1;
			d[p.second][0][0] = p.first;
			d[p.second][1][0] = x;
			dfs(p.second);
		}
	}
}

int calc(int x, int y) {
	int m = 0;
	if (r[x] < r[y]) {
		for (int i = 14; i >= 0; --i) {
			if (r[x] + (1 << i) <= r[y]) {
				m = max(m, d[y][0][i]);
				y = d[y][1][i];
			}
		}
	}
	if (r[x] > r[y]) {
		for (int i = 14; i >= 0; --i) {
			if (r[y] + (1 << i) <= r[x]) {
				m = max(m, d[x][0][i]);
				x = d[x][1][i];
			}
		}
	}
	if (x != y) {
		for (int i = 14; i >= 0; --i) {
			if (d[x][1][i] != d[y][1][i]) {
				m = max(m, d[x][0][i]);
				m = max(m, d[y][0][i]);
				x = d[x][1][i];
				y = d[y][1][i];
			}
		}
		m = max(m, d[x][0][0]);
		m = max(m, d[y][0][0]);
	}
	return m;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		cin >> a >> b >> c;
		q.push(mkp(c, mkp(a - 1, b - 1)));
	}
	memset(uf, -1, sizeof uf);
	while (!q.empty()) {
		if (u(q.top().second.first, q.top().second.second)) {
			v[q.top().second.first].push_back(mkp(q.top().first, q.top().second.second));
			v[q.top().second.second].push_back(mkp(q.top().first, q.top().second.first));
			e += q.top().first;
		}
		q.pop();
	}
	r[0] = 1;
	dfs(0);
	for (int i = 0; i < 14; ++i) {
		for (int j = 0; j < N; ++j) {
			d[j][0][i + 1] = max(d[j][0][i], d[d[j][1][i]][0][i]);
			d[j][1][i + 1] = d[d[j][1][i]][1][i];
		}
	}
	cin >> Q;
	while (Q--) {
		cin >> S >> T;
		cout << e - calc(S - 1, T - 1) << endl;
	}
}