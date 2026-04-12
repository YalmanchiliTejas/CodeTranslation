#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int D[100];
int dp[1 << 16];

vector<int> G[100];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N, M, K;
	cin >> N >> M >> K;
	memset(D, -1, sizeof D);

	int dn = 0;
	vector<int> ds;
	for(int i = 0; i < M; i++) {
		int x;
		cin >> x;
		x--;
		D[x] = dn++;
		ds.push_back(x);
	}

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < K; j++) {
			int v;
			cin >> v;
			G[i].push_back(v - 1);
		}
	}

	const int INF = 1 << 25;
	fill((int*)begin(dp), (int*)end(dp), INF);

	dp[(1 << M) - 1] = 0;
	queue<int> q;
	q.push((1 << M) - 1);
	while(q.size()) {
		int s = q.front();
		int t = dp[s];
		q.pop();
		for(int k = 0; k < K; k++) {
			int ns = 0;
			for(int i = 0; i < M; i++) {
				if(s >> i & 1) {
					int v = ds[i];
					int u = G[v][k];
					if(D[u] == -1) continue;
					ns |= 1 << D[u];
				}
			}
			if(ns == 0) {
				cout << t + 1 << endl;
				return 0;
			}
			if(dp[ns] > t + 1) {
				dp[ns] = t + 1;
				q.push(ns);
			}
		}
	}
	cout << -1 << endl;
}