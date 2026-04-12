#include <bits/stdc++.h>

int N;
std::vector <int> e[110000];
int size[110000];
int magic[110000];

int dfs (int x, int f = -1) {
	int d = 0, cnt = 0, cnt_ = 0, del = 1;
	for (int i = 0; i < e[x].size (); i++) {
		if (e[x][i] == f) continue;
		d = std::max (d, dfs (e[x][i], x));
		if (magic[e[x][i]] != 1) del = 0;
		if (magic[e[x][i]] == 2) {
			cnt++;
			magic[x] = 1;
		}
		if (magic[e[x][i]] == 1) {
			cnt_++;
		}
		size[x] += size[e[x][i]];
	}
	if (del) magic[x] = 2;
	size[x]++;
//	printf ("%d %d %d\n", x, magic[x], cnt);
	if (cnt >= 2) return 1;
	if (f == -1 && cnt_ >= 2 && del) return 1;
	return d;
}

int main () {
	scanf ("%d", &N);
	for (int i = 0; i < N - 1; i++) {
		int u, v;
		scanf ("%d%d", &u, &v);
		e[u].push_back (v);
		e[v].push_back (u);
	}
	int b = 1;
	while (b <= N && e[b].size () <= 1) ++b;
	if (b > N) {
		puts ("Second");
		return 0;
	}
	if (dfs (b))
		puts ("First");
	else
		puts ("Second");
	return 0;
}

