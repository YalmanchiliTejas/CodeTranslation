#include <bits/stdc++.h>
using namespace std;
bool vis[105][105];
char s[105][105];
int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++){
		scanf("%s", s[i]+1);
	}

	for(int i=1;i<=n;i++){
		bool ok = 1;
		for(int j=1;j<=m;j++){
			if(s[i][j] == '#') ok = 0;
		}
		if(!ok) continue;
		for(int j=1;j<=m;j++){
			vis[i][j] = 1;
		}
	}

	for(int i=1;i<=m;i++){
		bool ok = 1;
		for(int j=1;j<=n;j++){
			if(s[j][i] == '#') ok = 0;
		}
		if(!ok) continue;
		for(int j=1;j<=n;j++){
			vis[j][i] = 1;
		}
	}

	for(int i=1;i<=n;i++){
		bool ok = 0;
		for(int j=1;j<=m;j++){
			if(!vis[i][j]) printf("%c", s[i][j]), ok = 1;
		}
		if(ok) printf("\n");
	}
}