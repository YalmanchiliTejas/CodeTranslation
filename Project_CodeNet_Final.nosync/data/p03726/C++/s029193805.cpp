#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<list>
#include<queue>
#include<string.h>
#include<functional>
#include<stack>
#include<deque>
#include<string>
#include<limits.h>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#define P pair<int,int>
using namespace std;

P S[100000];
vector<int>r[100000];
int D[100000];
bool used[100001];
int p[100000];
void DFS(int a) {
	for (int b : r[a]) {
		if (D[b] == -1) {
			D[b] = D[a] + 1;
			p[b] = a;
			DFS(b);
		}
	}
}
signed main() {
	int n; cin >> n;
	for (int i = 1; i<n; i++) {
		int x, y; cin >> x >> y;
		x--; y--;
		r[x].push_back(y);
		r[y].push_back(x);
	}
	memset(D, -1, sizeof(D));
	used[n] = true;
	p[0] = n;
	D[0] = 0;
	DFS(0);
	for (int i = 0; i < n; i++) {  S[i] = { D[i],i }; }
	sort(S, S + n, greater<P>());
	for (int i = 0; i<n; i++) {
		if (used[S[i].second])continue;
		if (used[p[S[i].second]]) { puts("First"); return 0; }
		used[p[S[i].second]] = true;
	}
	puts("Second");
}