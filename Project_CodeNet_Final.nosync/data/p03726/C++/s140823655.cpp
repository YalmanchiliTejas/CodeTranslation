#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 100;

int n, d[N];
bool dead[N];
vector<int> nei[N];
queue<int> q;

void input() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		nei[--u].push_back(--v);
		nei[v].push_back(u);
	}
}

int match(int v) {
	for (int u: nei[v])
		if (dead[u] == false)
			return u;
	return -1;
}

bool have_matching() {
	if (n & 1)
		return false;
	for (int u = 0; u < n; u++)
		if ((d[u] = nei[u].size()) == 1)
			q.push(u);
	n >>= 1;
	while (n) {
		if (q.empty())
			return false;
		int v = q.front();
		q.pop();
		if (dead[v])
			continue;
		int u = match(v);
		if (u == -1)
			continue;
		dead[v] = dead[u] = true;
		for (int w: nei[u])
			if (dead[w] == false && --d[w] == 1)
				q.push(w);
		n--;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	input();
	if (have_matching())
		cout << "Second\n";
	else
		cout << "First\n";
}
