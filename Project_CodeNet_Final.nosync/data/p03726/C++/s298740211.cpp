#include <bits/stdc++.h>
#define endl '\n'
#define forn(i, n) for(int i=0;i<n;i++)
#define lli long long int
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back

using namespace std;

const int MAXN = 1000001;

int n;
int M[MAXN];
int out[MAXN];
int parent[MAXN];
vector<int> lista[MAXN];

int dfs(int u,int p) {
	forn(i, lista[u].size()) {
		int v = lista[u][i];
		if(v != p) {
			parent[v] = u;
			out[u]++;
			dfs(v, u);
		}
	}
}

int maxMatching() {
	queue<int> q;
	forn(i, n) {
		if(!out[i])
			q.push(i);
		M[i] = -1;
	}

	int ans = 0;
	while(!q.empty()) {
		int u = q.front();
		q.pop();

		if(u != parent[u] && M[ parent[u] ] == -1) {
			M[ parent[u] ] = u;
			M[u] = parent[u];
			ans++;

			u = parent[u];
			if(u != parent[u]) {
				out[ parent[u] ]--;
				if(!out[ parent[u] ])
					q.push(parent[u]);
			}
		}
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a,b;
	cin>>n;
	forn(i, n - 1) {
		cin>>a>>b;
		a--,b--;
		lista[a].pb(b);
		lista[b].pb(a);
	}
	dfs(0, -1);
	int ans = maxMatching();

	if(ans * 2 == n) cout<<"Second"<<endl;
	else cout<<"First"<<endl;
	return 0;
}
