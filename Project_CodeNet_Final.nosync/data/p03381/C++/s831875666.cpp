#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	while (~scanf("%d", &N)) {
		vector<int> A(N);
		for (int i = 0; i < N; ++i)
			scanf("%d", &A[i]);
		vector<pair<int, int>> v(N);
		for (int i = 0; i < N; ++i)
			v[i] = { A[i], i };
		sort(v.begin(), v.end());
		vector<int> ans(N);
		int h = N / 2 - 1;
		for (int i = 0; i < N; ++i)
			ans[v[i].second] = v[h + (i <= h)].first;
		for (int i = 0; i < (int)ans.size(); ++i)
			printf("%d\n", ans[i]);
	}
}
