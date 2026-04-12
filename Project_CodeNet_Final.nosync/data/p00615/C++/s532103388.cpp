#include "bits/stdc++.h"
using namespace std;

int main() {
	while (1) {

		int N, M; cin >> N >> M;
		if (!N&&!M)break;
		vector<int>vs(N + M);
		for (int i = 0; i < N + M; ++i) {
			cin >> vs[i];
		}
		vs.emplace_back(0);
		sort(vs.begin(), vs.end());
		int ans = 0;
		for (int i = 0; i < vs.size() - 1; ++i) {
			ans = max(ans, vs[i + 1] - vs[i]);
		}
		cout << ans << endl;
	}
	return 0;
}