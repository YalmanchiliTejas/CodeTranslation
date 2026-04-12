#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifdef _MSC_VER
	freopen("f.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a(n * 3);
	for (int i = 0; i < n * 3; i++) {
		cin >> a[i];
		--a[i];
	}
	vector<vector<int>> f(n, vector<int>(n, -1000000));
	int offset = 0;
	vector<pair<pair<int, int>, int>> updates;
	int opt = 0;
	vector<int> local(n, -1000000);
	f[a[0]][a[1]] = f[a[1]][a[0]] = 0;
	local[a[0]] = local[a[1]] = 0;
	for (int index = 2; index + 2 < n * 3; index += 3) {
		vector<int> b(3);
		for (int k = 0; k < 3; k++) {
			b[k] = a[index + k];
		}
		if (b[0] == b[1] && b[0] == b[2]) {
			++offset;
			continue;
		}
		updates.clear();
		for (int i = 0; i < 3; i++) {
			for (int j = i + 1; j < 3; j++) {
				int k = 3 - i - j;
				updates.push_back(make_pair(make_pair(b[i], b[j]), opt));
				updates.push_back(make_pair(make_pair(b[i], b[j]), f[b[k]][b[k]] + 1));
			}
		}
		for (int i = 0; i < 3; i++) {
			int j = (i + 1) % 3;
			int k = (j + 1) % 3;
			for (int x = 0; x < n; x++) {
				updates.push_back(make_pair(make_pair(b[i], x), local[x]));
				if (b[j] == b[k]) {
					updates.push_back(make_pair(make_pair(b[i], x), f[x][b[j]] + 1));
				}
			}
		}
		for (const auto& update : updates) {
			int x = update.first.first;
			int y = update.first.second;
			int val = update.second;
			if (val > f[x][y]) {
				f[x][y] = f[y][x] = val;
				opt = max(opt, val);
				local[x] = max(local[x], val);
				local[y] = max(local[y], val);
			}
		}
	}
	opt = max(opt, f[a.back()][a.back()] + 1);
	int ret = opt + offset;
	cout << ret << endl;
	return 0;
}
