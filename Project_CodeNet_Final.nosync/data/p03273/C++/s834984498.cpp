#include <bits/stdc++.h>
using namespace std;
char sq[110][110];
bool hang[110], lie[110];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++) scanf("%s", sq[i]+1);
	memset(hang, false, sizeof(hang)); memset(lie, false, sizeof(lie));
	for (int i=1; i<=n; i++) {
		bool flag=false;
		for (int j=1; j<=m; j++) 
			if (sq[i][j]=='#') {flag=true; break;}
		hang[i]=flag;
	}
	for (int i=1; i<=m; i++) {
		bool flag=false;
		for (int j=1; j<=n; j++) 
			if (sq[j][i]=='#') {flag=true; break;}
		lie[i]=flag;
	}
	for (int i=1; i<=n; i++) 
		if (hang[i]) {
			for (int j=1; j<=m; j++) 
				if (lie[j]) cout << sq[i][j];
			printf("\n");
		}
	return 0;
}