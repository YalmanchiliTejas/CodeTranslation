#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 100;

int n, u, v, maxi, cnt[N];
bool mark[N];
queue<int> q;
set<int> nei[N];

void add(int v) {
	for (int u: nei[v])
		maxi = max(maxi, ++cnt[u]);
}

bool ok(int v) {
	return nei[v].size() == 1;// && nei[*nei[v].begin()].size() <= 2;
}

void check(int v) {
	int u = *nei[v].begin();
	for (int w: nei[u]) {
		nei[w].erase(u);
		if(nei[w].size() == 1)
			add(w);
		if(ok(w))
			q.push(w);
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		nei[--u].insert(--v);
		nei[v].insert(u);
	}
	for (int i = 0; i < n; i++)
		if(nei[i].size() == 1)
			add(i);
	for (int i = 0; i < n; i++)
		if(ok(i))
			q.push(i);
	while(q.size())
		check(q.front()), q.pop();
	cout << (maxi > 1? "First": "Second");
	return 0;
}