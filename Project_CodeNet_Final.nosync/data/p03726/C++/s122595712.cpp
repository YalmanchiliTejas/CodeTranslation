#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

int N;
vi g[100010];
int c[100010];
int st[100010];
bool ok;
/*
void dfs(int v, int p)
{
	int s = 0;
	int c = 0;
	int codd = 0;
	int ceven = 0;
	bool only_path = 1;

	for (int to : g[v]) {
		if (to != p) {
			dfs(to, v);

			if (st[to] == 0) {
				++codd;
			} else if (st[to] == 1) {
				++ceven;
			} else {
				only_path = 0;
			}

			if (c) {
				s = -1;
			} else {
				if (st[to] == -1) {
					s = -1;
				} else {
					s = (st[to] ^ 1);
				}
			}

			++c;
		}
	}

	st[v] = s;

	if (codd >= 2 || (p == -1 && only_path && ceven > 0 && codd == 0)) {
		ok = 1;
	}
	//cout<<v<<" " << st[v] << endl;
}
*/

queue<int> que;
bool vis[100010];
int col[100010];
int sz[100010];

int main() {
	scanf("%d", &N);

	rep(i, N-1) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a; --b;
		g[a].pb(b); g[b].pb(a);
	}

	rep(i, N) {
		sz[i] = g[i].size();
		if (g[i].size() == 1) {
			 que.push(i);
		}
	}

	memset(col, -1, sizeof(col));

	while (!que.empty()) {
		int v = que.front(); que.pop();
		vis[v] = 1;
		
		col[v] = 0;
		int cnt = 0;
		int c1 = 0;

		for (int to : g[v]) {
			--sz[to];

			if (col[to] != -1) {
				if (col[to] == 0) {
					col[v] = 1;
					++cnt;
				} else {
					++c1;
				}
			}

			if (sz[to] <= 1 && !vis[to]) {
				que.push(to);
			}
		}
		if (cnt >= 2 || c1 == (int)g[v].size()) {
			ok = 1;
		}
	}

	puts(ok ? "First" : "Second");

	return 0;
}