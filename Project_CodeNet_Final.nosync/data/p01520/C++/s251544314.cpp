#include "bits/stdc++.h"
using namespace std;

int dx8[9] = { -1,-1,-1, 0, 1, 1, 1, 0 ,0};
int dy8[9] = { -1, 0, 1, 1, 1, 0,-1,-1,0 };
int main() {
	int N, T, E; cin >> N >> T >> E;
	int ans = -1;
	for (int aa = 0; aa < N;++aa) {
		int a; cin >> a;
		for (int i = 0; i < 10000; ++i) {
			if (a*i >= T - E&&a*i <= T + E)ans = aa+1;
		}
	}
	cout << ans << endl;
	return 0;
}