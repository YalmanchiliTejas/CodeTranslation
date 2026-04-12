#include <iostream>

#define rep(i,s,e) for (int i = s; i < e; ++i)
using namespace std;

static const int max_size = 9;
int N, M;
int C[max_size][max_size];
bool visited[max_size];
int c = 0;
void dfs(int n) {
	visited[n] = true;
	bool hasNext = false;
	rep(i, 1, N + 1) {
		if (!visited[i] && C[n][i] == 1) {
			hasNext |= true;
		}
	}

	if (!hasNext) {
		bool allVisited = true;
		rep(i, 1, N + 1) {
			allVisited &= visited[i];
		}
		if (allVisited) {
			c++;
		}
	}

	rep(i, 1, N + 1) {
		if (C[n][i] == 1 && !visited[i]) {
			dfs(i);
		}
	}
	visited[n] = false;
}

int main()
{
	cin >> N >> M;
	rep(i, 0, M) {
		int x, y; cin >> x >> y;
		C[x][y] = 1;
		C[y][x] = 1;
	}

	dfs(1);

	cout << c << endl;
	return 0;
}