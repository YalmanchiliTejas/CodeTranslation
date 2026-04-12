#include <iostream>
using namespace std;

bool road[9][9];
bool used[9];
int N, M, ans;

void checkroad(int now, int depth) {
	if (depth==0) {
		ans++;
		return;
	}

	used[now] = true;
	for (int to = 2; to <= N; to++) {
		if (used[to]) continue;
		if (road[now][to]) {
			checkroad(to, depth-1);
		}
	}
	used[now] = false;
}


int main(void) {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			road[i][j] = false;
		}
		used[i] = false;
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		road[a][b] = road[b][a] = true;
	}

	ans = 0;
	checkroad(1, N-1);
	cout << ans << endl;

  return 0;
}
