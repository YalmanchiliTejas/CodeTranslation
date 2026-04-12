#include<iostream>
#include<vector>

using namespace std;

int n, m;
vector<vector<int> > path(8);

int solve(int x,vector<int> ls) {
	int ans = 0;
	int flag = 1;
	vector<int> lsls(8, 0);
	for (int j = 0; j < n; j++) {
		lsls[j] = ls[j];
	}
	lsls[x] = 1;
	for (int i = 0; i < n; i++)
		flag*=lsls[i];
	if (flag == 1)
		return 1;
	for (int i = 0; i < path[x].size(); i++) {
		if (ls[path[x][i]] == 0) {
			ans += solve(path[x][i], lsls);
		}
	}
	return ans;
}

int main() {
	vector<int> list(8,0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		path[a-1].push_back(b-1);
		path[b-1].push_back(a-1);
	}
	list[0] = 1;
	cout << solve(0, list) << endl;
	return 0;
}
