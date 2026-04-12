#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int N, A[6666], D[2222][2222], R[2222], M;

int main()
{
	scanf ("%d", &N);
	for (int i = 0; i < N * 3; i++) scanf ("%d", &A[i]);
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++) D[i][j] = -1e9;
		R[i] = -1e9;
	}
	M = -1e9;

	D[A[0]][A[1]] = D[A[1]][A[0]] = 0;
	R[A[0]] = R[A[1]] = M = 0;

	int base = 0;
	for (int i = 2; i + 3 < N * 3; i += 3){
		sort(A + i, A + i + 3);

		if (A[i] == A[i + 2]){ base++; continue; }
		
		struct inst{ int x, y, c; };
		vector<inst> upd;

		int w = -1, v = -1, u = -1;
		if (A[i] == A[i + 1]) w = A[i], v = A[i + 2];
		if (A[i + 1] == A[i + 2]) w = A[i + 2], v = A[i];

		if (w != -1){
			for (int p = 1; p <= N; p++){
				upd.push_back({ p, v, D[w][p] + 1 });
				upd.push_back({ p, v, R[p] });
			}
			upd.push_back({ w, w, D[v][v] + 1 });
			upd.push_back({ w, w, M });
			upd.push_back({ w, v, D[w][w] + 1 });
			upd.push_back({ w, v, M });
		}
		else{
			for (int k = 0; k < 3; k++){
				if (k == 0) w = A[i + 1], v = A[i + 2];
				if (k == 1) w = A[i], v = A[i + 2];
				if (k == 2) w = A[i], v = A[i + 1];
				u = A[i + k];

				for (int p = 1; p <= N; p++) upd.push_back({p, u, R[p]});
				upd.push_back({ w, v, D[u][u] + 1 });
				upd.push_back({ w, v, M });
			}
		}

		for (auto& t : upd){
			int x = t.x, y = t.y;
			D[x][y] = max(D[x][y], t.c);
			R[x] = max(R[x], t.c);
			M = max(M, t.c);
			swap(x, y);
			D[x][y] = max(D[x][y], t.c);
			R[x] = max(R[x], t.c);
		}
	}

	int ans = max(M, D[A[3 * N - 1]][A[3 * N - 1]] + 1) + base;
	printf ("%d\n", ans);
	return 0;
}