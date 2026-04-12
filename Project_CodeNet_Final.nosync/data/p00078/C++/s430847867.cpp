#include <stdio.h>

int main(void){
	int n;
	int a[15][15];

	while(1){
		scanf("%d", &n);
		if(n == 0) break;

		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				a[i][j] = 0;
			}
		}

		int x = n/2;
		int y = n/2 + 1;
		a[x][y] = 1;
		for(int i=2; i<=n*n; i++){
			x++;
			y++;
			while(1){
				if(x < n && y < n && x >= 0 && a[x][y] == 0){
					a[x][y] = i;
					break;
				}else{
					if(x >= n){
						x = 0;
					}else if(y >= n){
						y = 0;
					}else if(x < 0){
						x = n-1;
					}else{
						x--;
						y++;
					}
				}
			}
		}

		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				printf("%4d", a[j][i]);
			}
			puts("");
		}
	}

	return 0;
}