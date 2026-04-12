#include <bits/stdc++.h>

using namespace std;

int n, m, row[105], col[105], del_row[105], del_col[105];
char a[105][105];

int main() {
	cin >> n >> m;
	char c;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) {
			cin >> c;
			int d = c == '#' ? 1 : 0;
			a[i][j] = c;
			if(!d) row[i]++, col[j]++;
		}
	for(int i = 1; i <= n; i++)
		if(row[i] == m) del_row[i] = 1;
	for(int j = 1; j <= m; j++)
		if(col[j] == n) del_col[j] = 1;
	for(int i = 1; i <= n; i++) {
		if(del_row[i]) continue;
		for(int j = 1; j <= m; j++)
			if(!del_col[j]) cout << a[i][j];
		cout << endl;
	}
	return 0;
}