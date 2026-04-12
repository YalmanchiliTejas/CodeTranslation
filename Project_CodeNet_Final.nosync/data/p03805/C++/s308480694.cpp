#include <bits/stdc++.h>

using namespace std;

#define INF 2000000000
#define MOD 1000000007
typedef long long ll;
typedef pair<int, int> P;

int n;
int m;
int cnt;
int p[10];
int adj[10][10];

void dfs(int pos, int mask) {
//	cout << pos << " " << mask << "\n";
	if (pos==n) {
		int c = 0;
		for (int i = 0; i < n-1; i++) {
			if (adj[p[i]][p[i+1]]==0) {
				c++;
				break;
			}
		}
		if (c==0) {
			cnt++;
		}
	}
	for (int i = 0; i < n; i++) {
		if ((mask & (1 << i)) != 0) {
			p[pos] = i;
			dfs(pos + 1, (mask ^ (1 << i)));
		}
	}
}

int main()
{
	cin >> n >> m;
	memset(p, 0, sizeof(p));
	cnt = 0;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		adj[a][b]=1;
		adj[b][a]=1;
	}
	dfs(1, (1 << n) - 2);
	cout << cnt << "\n";
}
