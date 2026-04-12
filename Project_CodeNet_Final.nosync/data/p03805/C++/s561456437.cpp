#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, M, a, b,rootCount = 0;
	cin >> N >> M;
	vector<pair<int, int>> vec(M);

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		vec[i] = make_pair(a, b);
	}

	vector<int> vertex(N);
	for (int i = 0; i < N; i++) {
		vertex[i] = i + 1;
	}

	bool flg;
	do {
		if (vertex[0] == 1) {
			for (int i = 0; i < vertex.size() - 1; i++)
			{
				flg = false;
				for (auto pii : vec)
				{
					if ((vertex[i] == pii.first && vertex[i + 1] == pii.second) ||
						(vertex[i] == pii.second && vertex[i + 1] == pii.first))
					{
						flg = true;
						break;
					}
				}

				if (!flg)
				{
					break;
				}
			}

			if (flg)
			{
				rootCount++;
			}
		}
	} while (next_permutation(vertex.begin(), vertex.end()));

	cout << rootCount;
}