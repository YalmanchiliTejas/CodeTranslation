#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, a[100], b[100];

int e[10][10];
vector<int > V;

int CHECK(void) {

	int cur = 1;

	for (int i = 0; i <= N - 2; i++) {
		int next = V[i];
		if (e[cur][next] == 0) { return -1; }
		cur = next;
	}
	return 1;
}

int main(void) {

	cin >> N >> M;

	for (int i = 1; i <= M; i++) {
		cin >> a[i] >> b[i];
		e[a[i]][b[i]] = 1;
		e[b[i]][a[i]] = 1;
	}

	

	for (int i = 2; i <= N; i++) { V.push_back(i); }
	int ans = 0;
	do {
		if (CHECK() == 1) { ans++; }
	} while (next_permutation(V.begin(), V.end()));

	cout << ans << endl;
	return 0;
}