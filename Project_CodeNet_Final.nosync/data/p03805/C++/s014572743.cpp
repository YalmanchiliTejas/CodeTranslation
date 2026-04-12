#include <iostream>

using namespace std;

int p[10];
int N, M;
bool edge[10][10];
int match = 0; // 何通りあるか

// 順列を探す。
// pos : 位置, mask : 集合
void dfs(int pos, int mask) {
	if (pos == N) {
		// 順列が見つかった
		if (p[0] != 0) return; // 最初が0(1)で無かったら終了

		for (int i = 0; i < N - 1; i++) {
			if (!edge[p[i]][p[i + 1]]) {
				// つながってないンゴ]
				return;
			}
		}
		match++;

		return;
	}

	for (int i = 0; i < N; i++) {
		if (mask & (1 << i)) {
			p[pos] = i; // i確定
			dfs(pos+1, (mask^(1<<i))); // iを取り除いてdfs
		}

	}

}


int main() {
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		edge[a - 1][b - 1] = true;
		edge[b - 1][a - 1] = true;
	}

	dfs(0, (1<<N) - 1);

	cout << match << endl;

	return 0;
}

