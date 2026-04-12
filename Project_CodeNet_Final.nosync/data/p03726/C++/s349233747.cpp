#include <bits/stdc++.h>
#define ll long long
#define mk make_pair
using namespace std;
 
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
const int inf = 1e9;
  
int n;
bool ok, bo[N];
vector<int> G[N];

void dfs(int x, int f) {
	if (G[x].size() == 1) bo[x] = 1;
	int tmp = 0;
	for (int i = 0; i < G[x].size(); i++) {
		int u = G[x][i];
		if (u == f) continue;
		dfs(u, x);
		if (bo[u]) tmp++;
	}
	if (tmp == 0) bo[x] = 1;
	if (tmp > 1) ok = 1;
}

int main() {
  cin >> n;
  for (int i = 1; i < n; i++) {
  	int x, y;
  	scanf("%d %d", &x, &y);
  	G[x].push_back(y);
  	G[y].push_back(x);
	}
	if (n & 1) ok = 1;
	dfs(1, 0);
	if (ok) puts("First");
	else puts("Second");
}