#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#define N 100005
using namespace std;
typedef long long ll;
ll x;
int n, m;
bool mat[10][10];
int ans;
void dfs(int num, int cur, bool* vis) {
	if (num == n) {
		ans++;
		return;
	}
	for (int i = 1; i <= n; ++i) {
		if (!vis[i] && mat[cur][i]) {
			vis[i] = true;
			dfs(num+1, i, vis);
			vis[i] = false;
		}
	}
}
int main() {
	cin>>n>>m;
	memset(mat, false, sizeof(mat));
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin>>a>>b;
		mat[a][b] = mat[b][a]= true;
	}
	ans=0;
	bool vis[10];
	memset(vis, false, sizeof(vis));
	vis[1] = true;
	dfs(1, 1, vis);
	vis[1]= false;
	cout<<ans<<endl;
	return 0;
}