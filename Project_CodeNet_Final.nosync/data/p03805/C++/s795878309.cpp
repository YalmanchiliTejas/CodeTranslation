#include<bits/stdc++.h>
#pragma warning(disable:4996)
using namespace std;
using ll = long long;
const int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
bool used[1000];
int perm[1000];
int N, M;
int ans;
vector<vector<int>>edge(N, vector<int>(N));
void permutation1(int pos, int n) {
	if (pos == n) {
		
		if (perm[0] == 0) {
			bool ok = true;
			for (int i = 0; i < N-1; i++) {
				if (!edge[perm[i]][perm[i + 1]]) {
					ok = false;
				}
			}
			if (ok) {
				ans ++;
			}
		}
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			perm[pos] = i;
			used[i] = true;
			permutation1(pos + 1, n);
			used[i] = false;
		}
	}
	return;
}
int main() {
	cin >> N >> M;
	edge.resize(N);
	for (int i = 0; i < N; i++) {
		edge[i].resize(N);
	}
	
		for (int j = 0; j < M; j++) {
			int a, b;
			cin >> a >> b;
			a--; b--;
			edge[a][b] = true;
			edge[b][a] = true;
		}
	

	permutation1(0, N);
	cout << ans << endl;
}