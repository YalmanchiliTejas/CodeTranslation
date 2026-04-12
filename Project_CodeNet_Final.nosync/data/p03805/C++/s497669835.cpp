#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> e[8];
int ans = 0;

void dfs(int pos, int visited) {
		visited |= (1<<pos);
		if (__builtin_popcount(visited) == N) {
				ans++;
				return;
		}

		for (auto itr = e[pos].begin(); itr < e[pos].end(); itr++) {
				if (visited & (1<<(*itr))) continue;
				dfs(*itr, visited);
		}
}

int main() {
		cin >> N >> M;
		for (int i = 0; i < M; i++) {
				int a, b;
				cin >> a >> b;
				a--; b--;
				e[a].push_back(b);
				e[b].push_back(a);
		}

		dfs(0, 0);

		cout << ans << endl;

		return 0;
}
