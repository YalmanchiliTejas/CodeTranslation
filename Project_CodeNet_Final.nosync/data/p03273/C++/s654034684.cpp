#include <bits/stdc++.h>
using namespace std;
char a[120][120];
bool vis[120][120];
int n, m;
int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		scanf("%s", a[i] + 1);
	for(int i = 1; i <= n; i++) {
		bool flag = true;
		for(int j = 1; j <= m; j++)
			if(a[i][j] != '.') {
				flag = false;
				break;
			}
		if(flag) {
			for(int j = 1; j <= m; j++) {
				vis[i][j] = true;
			}
		}
	}
	for(int i = 1; i <= m; i++) {
		bool flag = true;
		for(int j = 1; j <= n; j++)
			if(a[j][i] != '.') {
				flag = false;
				break;
			}
		if(flag) {
			for(int j = 1; j <= n; j++) {
				vis[j][i] = true;
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		bool flag = false;
		for(int j = 1; j <= m; j++)
			if(vis[i][j] == false) {
				printf("%c", a[i][j]);
				flag = true;
			}
		if(flag == true) puts("");
	}
	return 0;
}
