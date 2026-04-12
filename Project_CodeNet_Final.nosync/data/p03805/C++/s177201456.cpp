#include "bits/stdc++.h"
using namespace std;
int N;
vector<int>to[100005];

int main() {
	int N, M;
	cin >> N >> M;
	for (int n = 0; n < M; ++n) {
		int a, b;
		cin >> a >> b;
		to[a].push_back(b);
		to[b].push_back(a);
	}
	int ans = 0;
	vector<int> v;
	for (int n = 0; n < N; ++n) {
		v.push_back(n + 1);
	}
	do {
		bool b = true;
		for (int i = 0;i<v.size()-1;++i) {
			bool b2 = false;
			for (int e : to[v[i]]) {
				if (e == v[i+1]) {
					b2 = true;
					break;
				}
			}
			if (!b2) {
				b = false;
			}
		}
		if (b) {
			ans++;
		}
	} while (next_permutation(v.begin()+1, v.end()));

	cout << ans << endl;
	return 0;
}