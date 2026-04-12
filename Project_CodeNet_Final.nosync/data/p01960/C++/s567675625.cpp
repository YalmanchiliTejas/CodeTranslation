#include<bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int n, k;
vector<int> G[100001];
int cnt[100001];
int gettt[100001];
int val[100001];
int ans = 0;

int dfs(int v, int p) {
	int ans = 1;
	for (int i = 0; i < G[v].size(); i++) {
		if (G[v][i] != p) {
			ans += dfs(G[v][i], v);
		}
	}
	return (cnt[v] = ans);
}

void solve(int v, int p) {
	int maxi = -1;
	int tp = n;
	for (int i = 0; i < G[v].size(); i++) {
		int nv = G[v][i];
		if (nv != p) {
			solve(nv, v);
		}
	}
	for (int i = 0; i < G[v].size(); i++) {
		int nv = G[v][i];
		if (nv != p) {
			int cv = val[nv];
			if (cnt[nv] >= k) {
				cv--;
			}
			if (maxi <= cv) {
				if (maxi < cv)tp = cnt[v];
				else tp = min(cnt[v], tp);
				maxi = max(cv, maxi);
			}
		}
	}
	int tmp = 0;
	if (n - cnt[v] >= k)tmp++;
	ans = max(ans, maxi + tmp + gettt[v]);
	//printf("%d\n",maxi);

	val[v] = max(val[v], maxi+gettt[v]);
	//printf("%d an1=%d va=%d\n",v,ans,val[v]);
	maxi = -1;
	int maxi2 = -1;
	if (G[v].size() <= 2)return;
	for (int i = 0; i < G[v].size(); i++) {
		int nv = G[v][i];
		if (nv != p) {
			int cv = val[nv];
			if (cnt[nv] >= k) {
				cv--;
			}
			if (maxi < cv) {
				maxi2 = maxi;
				maxi = cv;
			} else if (maxi2 < cv) {
				maxi2 = cv;
			}
		}
	}
	//printf("%d %d %d %d\n",v,maxi,maxi2,gettt[v]);
	//printf("%d %d\n",val[v],tmp);
	ans = max(ans, maxi + maxi2 + tmp + gettt[v]);
	//printf("%d an2=%d\n",v,ans);
}

int main(void) {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		u--;
		v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < G[i].size(); j++) {
		}
	}
	dfs(0, -1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < G[i].size(); j++) {
			int nv = G[i][j];
			if (cnt[nv] < cnt[i]) {
				if (cnt[nv] >= k)gettt[i]++;
			}
		}
		val[i] = gettt[i];
	}
	solve(0, -1);
	printf("%d\n", ans);
	return 0;
}