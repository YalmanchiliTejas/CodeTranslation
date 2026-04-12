#include <stdio.h>

int a[20][20];
int n;
int cnt;

int fills(int x, int y){
	if(x >= n){
		x -= n;
	}else if(x < 0){
		x += n;
	}
	if(y >= n){
		y -= n;
	}else if(y < 0){
		y += n;
	}
	if(a[x][y] != 0){
		return 1;
	}else{
		a[x][y] = cnt;
		cnt++;
	}
	if(fills(x + 1, y + 1)){
		fills(x + 2, y);
	}

	return 0;
}

int main(void)
{

	scanf("%d",&n);
	while(n != 0){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				a[i][j] = 0;
			}
		}
		cnt = 1;
		fills((n + 1) / 2, (n - 1) / 2);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(a[i][j] >= 100){
					printf(" %d",a[i][j]);
				}else if(a[i][j] >= 10){
					printf("  %d",a[i][j]);
				}else{
					printf("   %d",a[i][j]);
				}
			}
			printf("\n");
		}
		scanf("%d",&n);
	}
	return 0;
}