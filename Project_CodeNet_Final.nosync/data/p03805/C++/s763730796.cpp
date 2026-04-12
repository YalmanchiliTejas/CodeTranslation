#include <iostream>
#include <queue>
using namespace std;

#define MAX 30

int n, m;
bool map[MAX][MAX] = { false };

inline bool hasNext(bool a[]) {
	bool judge = true;
	for (int i = 0; i < n; i++) {
		if (a[i]) {
			judge = false;
			break;
		}
	}
	return judge;
}

int solve(int num, bool visit[]) {
	if (hasNext(visit)) {
		return 1;
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (!map[num][i] || !visit[i]) continue;

		visit[i] = false;
		ans += solve(i, visit);
		visit[i] = true;
	}
	return ans;
}

int main() {
	cin >> n >> m;

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		a--, b--;
		map[a][b] = true;
		map[b][a] = true;
	}

	bool visit[8] = { false };
	for (int i = 1; i < n; i++) visit[i] = true;
	cout << solve(0, visit) << endl;
	
	return 0;
}