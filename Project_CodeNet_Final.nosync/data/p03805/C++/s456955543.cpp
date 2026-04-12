#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PI;
typedef pair<LL, LL> PLL;
const LL MOD = 1000000007LL;
const int inf = 1e9;
const LL INF = 1e18;
bool connect[8][8];
int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b; a--; b--;
		connect[a][b] = connect[b][a] = 1;
	}
	int perm[8];
	for (int i = 0; i < N; i++) perm[i] = i;
	int ans = 0;
	do {
		bool OK = 1;
		for (int i = 1; i < N; i++) {
			if (!connect[perm[i - 1]][perm[i]]) {
				OK = 0;
				break;
			}
		}
		if (OK) ans++;
	} while (next_permutation(perm + 1, perm + N));
	cout << ans << endl;
}