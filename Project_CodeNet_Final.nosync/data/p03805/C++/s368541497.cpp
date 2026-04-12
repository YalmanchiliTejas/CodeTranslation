#include <bits/stdc++.h>
using namespace std;

#define pb         push_back

typedef long long ll;
const ll INF = 1000000000ll;
const ll MOD = 1000000007ll;
const double EPS = 1e-8;

int adj[100][100];
int ans = 0;
int used[100];
int n, m;

void dfs(int i, int cnt){
	if(cnt == n){
		ans++;
		return;
	}

	for(int j=0; j<n; j++){
		if(adj[i][j] == 1 && used[j] != 1){
			used[j] = 1;
			dfs(j, cnt+1);
			used[j] = 0;
		}
	}

}

int main(void) {
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	
	cin >> n >> m;

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			adj[i][j] = 0;
		}
	}

	for(int i=0; i<m; i++){
		int t1, t2;
		cin >> t1 >> t2;
		t1--;
		t2--;
		adj[t1][t2] = adj[t2][t1] = 1;
	}

	used[0] = 1;
	dfs(0, 1);

	cout << ans << endl;
	
	return 0;
}
