#include <iostream>
using namespace std;

int N, M, ans = 0;
int que[10], aa[9][9];

int dfs(int a, int step)
{
	if (step == N) { ++ans; return 0; }
	for (int i = 1; i <= N; ++i) {
		if (aa[a][i] == 1 && que[i] == 0) {
			que[i] = 1;
			dfs(i, step + 1);
			que[i] = 0;
		}
	}

	return 0;
}

int main(int argc, char **argv)
{
	int a, b;
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		cin >> a >> b;
		aa[a][b] = aa[b][a] = 1;
	}
	que[1] = 1;
	dfs(1, 1);
	cout << ans << endl;

	return 0;
}