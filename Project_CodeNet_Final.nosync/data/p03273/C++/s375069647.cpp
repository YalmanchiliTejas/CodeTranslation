#include <bits/stdc++.h>
using namespace std;

int main(){
	int h, w;
	char s[101][101];
	int row[100] = {0}, col[100] = {0};
	scanf("%d%d", &h, &w);
	for(int i=0; i < h; i++)
		scanf("%s", s[i]);
	for(int i=0; i < h; i++) {
		for(int j=0; j < w; j++) {
			if(s[i][j] == '#') {
				row[i] = 1;
				col[j] = 1;
			}
		}
	}

	for(int i=0; i < h; i++) {
		if(row[i]) {
			for(int j=0; j < w; j++) {
				if(col[j])
					printf("%c", s[i][j]);
			}
			printf("\n");
		}
	}
}
