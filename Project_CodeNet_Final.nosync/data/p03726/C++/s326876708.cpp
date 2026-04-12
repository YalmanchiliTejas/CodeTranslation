#include <iostream>
#include <vector>
#include <set>
using namespace std;

int N;
vector<int> C;
set<int> L;
vector<bool> used;
vector<vector<int> > P;

void l_check(void) {
	L.clear();
	for (int i = 0; i < N; ++i) {
		if (C[i] == 1)
			L.insert(i);
	}
}

int solve(void) {
	while (L.size()) {
		int leaf = *L.begin();
		L.erase(L.begin());
		for (int i = 0; i < (int)P[leaf].size(); ++i) {
			int rank1 = P[leaf][i];
			if (used[rank1])
				continue;
			used[leaf] = used[rank1] = true;
			for (int j = 0; j < (int)P[rank1].size(); ++j) {
				int rank2 = P[rank1][j];
				if (!used[rank2]) {
					--C[rank2];
					if (C[rank2] == 0)
						return 1;
					if (C[rank2] == 1)
						L.insert(rank2);
				}
			}
		}
	}
	return 0;
}

int main(void) {
	cin >> N;
	C.resize(N, 0);
	P.resize(N);
	for (int i = 1; i <= N - 1; ++i) {
		int a, b;
		cin >> a >> b;
		--a;	--b;
		++C[a];	++C[b];
		P[a].push_back(b);
		P[b].push_back(a);
	}

	l_check();
	used.resize(N, false);

	int win = solve();
	if (win == 1)
		cout << "First\n";
	else
		cout << "Second\n";
	return 0;
}
