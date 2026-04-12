#include <vector>
#include <iostream>

using namespace std;

int N, M;
bool e[8][8];
int ans = 0;
int p[8];

void dfs(int pos, int mask) {
		if (pos == N) {
				for (int i = 0; i < N-1; i++) {
						if (p[0] != 0) return;
						else if (!e[p[i]][p[i+1]]) return;
				}
				ans++;
				return;
		}

		for (int i = 0; i < N; i++) {
				if (mask & (1<<i)) {
						p[pos] = i;
						dfs(pos+1, (mask^(1<<i)));
				}
		}
}

int main() {
		cin >> N >> M;
		vector<int> v[N];
		for (int i = 0; i < M; i++) {
				int a, b;
				cin >> a >> b;
				a--; b--;
				e[a][b] = true;
				e[b][a] = true;
		}

		dfs(0, (1<<N) - 1);
		cout << ans << endl;
		return 0;
}
