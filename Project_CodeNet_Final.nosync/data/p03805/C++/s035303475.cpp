#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
const double PI = 3.141592653589793238;
const double EPS = 1e-10;
bool can[8][8];
int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		can[u][v] = can[v][u] = 1;
	}
	int perm[8];
	int ans = 0;
	for (int i = 0; i < N; i++) perm[i] = i;
	do {
		bool ok = 1;
		for (int i = 0; i + 1 < N; i++) {
			if (!can[perm[i]][perm[i + 1]]) {
				ok = 0;
				break;
			}
		}
		if (ok) ans++;
	} while (next_permutation(perm + 1, perm + N));
	cout << ans << endl;
}
