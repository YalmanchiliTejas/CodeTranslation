#include <bits/stdc++.h>
using namespace std;
const int N = 8 + 10;
string s[N];
int n, m, mark[N][N];
int dx[] = {1, 0}, dy[] = {0, 1};
bool isval(int x, int y) {
	if (x >= 0 && y >= 0 && x < n && y < m && s[x][y] == '#') 
		return true;
	return false;
}
void dfs(int x, int y) {
	mark[x][y] = 1;
	for (int i = 0; i < 2; i++) {
		if (isval(x + dx[i], y + dy[i])) {
			dfs(x + dx[i], y + dy[i]);
			return;
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	dfs(0, 0);
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) {
			if (s[i][j] == '#' && !mark[i][j]) {
				cout << "Impossible";
				return 0;
			}		
		}
	cout << "Possible";
	return 0;
}	
