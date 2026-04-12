#include <bits/stdc++.h> // Tomasz Nowak
using namespace std;     // XIII LO Szczecin
using L = long long;

struct Tree {
	int size = 1;
	vector<L> values, lazy;

	Tree(int n) {
		while(size < n)
			size *= 2;
		values.resize(size * 2);
		lazy = values;
	}

	L getMax() {
		return values[1];
	}

	void add(int l, int r, L val, int subSize, int v = 1) {
		if(l == 0 && r == subSize - 1) {
			values[v] += val;
			lazy[v] += val;
			return;
		}

		int s2 = subSize / 2;
		if(r < s2)
			add(l, r, val, s2, 2 * v);
		else if(l >= s2)
			add(l - s2, r - s2, val, s2, 2 * v + 1);
		else  {
			add(l, s2 - 1, val, s2, 2 * v);
			add(0, r - s2, val, s2, 2 * v + 1);
		}

		values[v] = max(values[2 * v], values[2 * v + 1]) + lazy[v];
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<vector<pair<int, L>>> req(n + 1);

	for(int i = 0; i < m; ++i) {
		int l, r, score;
		cin >> l >> r >> score;
		req[r].emplace_back(l, score);
	}

	Tree dp(n + 1);

	for(int i = 1; i <= n; ++i) {
		dp.add(i, i, dp.getMax(), dp.size);

		for(auto p : req[i])
			dp.add(p.first, i, p.second, dp.size);
	}
	cout << dp.getMax() << '\n';
}

