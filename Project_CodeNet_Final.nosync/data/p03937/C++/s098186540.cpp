#include<bits/stdc++.h>
using namespace std;
int n, m;
char mat[8][8];
int main() {
	cin >> n >> m;
	int c = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) {
			cin >> mat[i][j];
			if(mat[i][j] == '#') c++;
		}
	if(c != n+m-1) return cout << "Impossible", 0;
	for(int i = 0; i < 1<<(n+m-2); i++) {
		int x = 0, y = 0, cc = mat[1][1]=='#';
		for(int j = 0; j < n+m-2; j++) {
			if((i>>j)&1) x++;
			else y++;
			if(x >= n || y >= m) break;
			cc += mat[x][y] == '#';
		}
		if(cc != n+m-1) return cout << "Possible", 0;
	}
	cout << "Impossible";
}
