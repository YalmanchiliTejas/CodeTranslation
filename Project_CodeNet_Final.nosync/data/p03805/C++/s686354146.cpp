#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<string>
#include<limits.h>
#include<utility>
#include<bits/stdc++.h>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i,n) for(int i=0;i<n;i++)
#define ALL(A) A.begin(),A.end()
bool comparator(P a, P b) {
	return a.first / a.second < b.first / b.second;
}
int dfs(int n, vector<bool> ver, int N, vector<vector<bool>> path) {
	ver[n] = true;
	bool last = true;
	rep(i, N) {
		last = last && ver[i];
	}
	if (last) {

		return 1;
	}
	ll ans = 0;
	rep(i, N) {
		if (!ver[i]&&path[i][n]) {
			ans += dfs(i, ver, N, path);
			//cout << ans << endl;
		}
	}
	return ans;
}
int main() {
	int n, m;
	cin >> n >> m;
	vector < vector < bool>> path(n, vector<bool>(n, false));
	rep(i, m) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		path[a][b] = true;
		path[b][a] = true;
	}
	vector<bool> ver(n, false);
	//ver[0] = true;
	cout << dfs(0, ver, n, path) << endl;
}
