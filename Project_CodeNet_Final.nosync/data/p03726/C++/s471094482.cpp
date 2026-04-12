#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(V) V.begin(),V.end()

priority_queue<pair<int, int>> Q;
vector<int> G[100010];
int rt[100010], par[100010], out[100010];

void rf(int x, int c) {
	rt[x] = c;
	if (x != 0&&G[x].size() == 1)
		Q.push({ c,x });
	for (int i : G[x]) {
		if (rt[i]) {
			par[x] = i;
			continue;
		}
		rf(i, c + 1);
		out[x]++;
	}
}

int main() {
	int N, a, b, g;
	cin >> N;
	for (int i = 1;i < N;i++) {
		cin >> a >> b;
		a--;b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	rf(0, 1);

	while (!Q.empty()) {
		tie(g, b) = Q.top();
		Q.pop();
		if (b == 0) {
			cout << "First" << endl;
			return 0;
		}
		a = par[b];
		if (a == 0)continue;
		if (out[a] == 1) {
			out[par[a]]--;
			if (out[par[a]] == 0) {
				Q.push({ g - 2,par[a] });
			}
		}
	}
	for (int i = 0;i < N;i++) {
		if (out[i] > 1) {
			cout << "First" << endl;
			return 0;
		}
	}
	cout << "Second" << endl;
	return 0;
}