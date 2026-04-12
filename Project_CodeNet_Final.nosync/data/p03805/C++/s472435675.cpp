#include <iostream>
#include <vector>
using namespace std;

int r(int pos, bool edges[8][8], bool memo[8], int N) {
	int result = 0;

	bool unfinished = false;
	for (int i=0; i<N; i++) if (!memo[i]) unfinished = true;
	if (!unfinished) return 1;

	for (int i=0; i<N; i++) {
		if (!memo[i] && edges[pos][i]) {
			memo[i] = true;
			result += r(i, edges, memo, N);
			memo[i] = false;
		}
	}

	return result;
}

int main() {
	int N, M;
	cin >> N >> M;

	bool edges[8][8];
	for (int i=0; i<N; i++) for (int j=0; j<N; j++) edges[i][j] = false;
	for (int i=0; i<M; i++) {
		int a, b;
		cin >> a >> b; a--; b--;
		edges[a][b] = edges[b][a] = true;
	}

	bool memo[8];
	for (int i=0; i<N; i++) memo[i] = false;
	memo[0] = true;
	cout << r(0, edges, memo, N) << endl;
	return 0;
}
