#include <bits/stdc++.h>
using namespace std;

// why am I so weak

int n, m;
char mat[8][9];

int main() {
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < n; i++) scanf("%s", mat[i]);
	
	int pos = 0;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < pos; j++) if (mat[i][j] == '#') return 0 * printf("Impossible");
		
		if (mat[i][pos] != '#') return 0 * printf("Impossible");
		
		for (int j = pos + 1; j < m; j++) {
			if (mat[i][j] == '#') {
				if (pos + 1 != j) {
					return 0 * printf("Impossible");
				}
				
				pos = j;
			}
		}
	}
	
	puts("Possible");
	
	return 0;
}
