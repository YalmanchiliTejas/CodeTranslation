#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, a[100], b[100];

int A[10][10];

int main(void) {

	cin >> N >> M;

	for (int i = 1; i <= M; i++) {
		cin >> a[i] >> b[i];
	}

	for (int i = 1; i <= M; i++) {
		A[a[i]][b[i]] = 1;
		A[b[i]][a[i]] = 1;
	}

	int ans = 0;
	vector<int> V;
	for (int i = 1; i <= N; i++) {
		V.push_back(i);
	}

	do {
		if (V[0] != 1) { continue; }

		int sign = 1;
		for (int i = 0; i < N-1; i++) {
			if (A[V[i]][V[i + 1]] == 0) { sign = -1; break; }
		}
		if (sign == 1) { ans++; }

	} while (next_permutation(V.begin(), V.end()));

	cout << ans << endl;

	//system("pause");
	return 0;
}