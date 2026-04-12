#include <bits/stdc++.h>

using namespace std;

int n, x[6005], y[2005][2005], add, ans, mx[2005], mxx;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n * 3; i++)
		scanf("%d", x + i);
	for (int i = 1; i <= n; i++) {
		mx[i] = INT_MIN;
		for (int j = 1; j <= n; j++)
			y[i][j] = INT_MIN;
	}
	mx[x[0]] = mx[x[1]] = 0;
	y[x[0]][x[1]] = y[x[1]][x[0]] = 0;
	for (int i = 2; i + 3 <= n * 3; i += 3) {
		sort(x + i, x + i + 3);
		vector<tuple<int, int, int>> v;
		if (x[i] == x[i + 2]) {
			add++;
			continue;
		}
		if (x[i] == x[i + 1])
			for (int j = 1; j <= n; j++)
				v.emplace_back(j, x[i + 2], y[x[i]][j] + 1);
		else if (x[i + 1] == x[i + 2])
			for (int j = 1; j <= n; j++)
				v.emplace_back(j, x[i], y[x[i + 1]][j] + 1);
		for (int j = i; j < i + 3; j++)
			v.emplace_back(j == i ? x[i + 1] : x[i], j == i + 2 ? x[i + 1] : x[i + 2], y[x[j]][x[j]] + 1);
		v.emplace_back(x[i], x[i + 1], mxx);
		v.emplace_back(x[i], x[i + 2], mxx);
		v.emplace_back(x[i + 1], x[i + 2], mxx);
		for (int j = 1; j <= n; j++)
			for (int k = i; k < i + 3; k++)
				v.emplace_back(j, x[k], mx[j]);
		for (auto& j : v) {
			int ta, tb, tc;
			tie(ta, tb, tc) = j;
			y[ta][tb] = max(y[ta][tb], tc);
			y[tb][ta] = max(y[tb][ta], tc);
			mx[ta] = max(mx[ta], tc);
			mx[tb] = max(mx[tb], tc);
			mxx = max(mxx, tc);
		}
	}
	y[x[n * 3 - 1]][x[n * 3 - 1]]++;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			ans = max(ans, y[i][j]);
	printf("%d\n", ans + add);
}