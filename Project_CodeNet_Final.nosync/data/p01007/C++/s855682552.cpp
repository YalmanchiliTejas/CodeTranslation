#include <stdio.h>
#include <string.h>
#define MAX_N 15

void rotate90(int r,int c,int size,int a[MAX_N][MAX_N]){
	int b[MAX_N][MAX_N], i, j;

	for(i = 0;i < size;i++){
		for(j = 0;j < size;j++){
			b[r + i][c + j] = a[r + i][c + j];
		}
	}


	for(i = 0;i < size;i++){
		for(j = 0;j < size;j++){
			b[r + i][c + j] = a[size + r - j - 1][c + i];
		}
	}
	for(i = 0;i < size;i++){
		for(j = 0;j < size;j++){
			a[r + i][c + j] = b[r + i][c + j];
		}
	}
}

void rotate(int r,int c,int size,int angle,int a[MAX_N][MAX_N]){
	int i;
	for(i = 0;i < (angle / 90) % 4;i++){
		rotate90(r,c,size,a);
	}
}


void reversal(int r,int c,int size,int a[MAX_N][MAX_N]){
	int i, j;
	for(i = 0;i < size;i++){
		for(j = 0;j < size;j++){
			if(a[r + i][c + j] == 0){
				a[r + i][c + j] = 1;
			}else{
				a[r + i][c + j] = 0;
			}
		}
	}
}

void left_shift(int r,int n,int a[MAX_N][MAX_N]){
	int j, tmp;
	tmp = a[r][0];
	for(j = 1;j < n;j++){
		a[r][j - 1] = a[r][j];
	}
	a[r][n - 1] = tmp;
}

void right_shift(int r,int n,int a[MAX_N][MAX_N]){
	int j, tmp;
	tmp = a[r][n - 1];
	for(j = n - 2;j >= 0;j--){
		a[r][j + 1] = a[r][j];
	}
	a[r][0] = tmp;
}

void island_reversal(int r,int c,int n,int a[MAX_N][MAX_N]){
	int i, j;
	const int dy[4] = {-1,0,0,1}, dx[4] = {0,-1,1,0};

	int tmp = a[r][c];
	a[r][c] = !a[r][c];
	for(i = 0;i < 4;i++){
		if(0 <= r + dy[i] && r + dy[i] < n && 0 <= c + dx[i] && c + dx[i] < n && tmp == a[r + dy[i]][c + dx[i]]){
			island_reversal(r + dy[i],c + dx[i],n,a);
		}
	}
}

int main(void){
	int a[MAX_N][MAX_N], i, j, n, m, ope, r, c, size,angle;


	scanf("%d%d",&n,&m);
	
	for(i = 0;i < n;i++){
		for(j = 0;j < n;j++){
			scanf("%d",&a[i][j]);
		}
	}

	for(i = 0;i < m;i++){

		scanf("%d",&ope);
		switch(ope){
		case 0:
			scanf("%d%d%d%d",&r,&c,&size,&angle);
			rotate(r - 1,c - 1,size,angle,a);
			break;
		case 1:
			scanf("%d%d%d",&r,&c,&size);
			reversal(r - 1,c - 1,size,a);
			break;
		case 2:
			scanf("%d",&r);
			left_shift(r - 1,n,a);
			break;
		case 3:
			scanf("%d",&r);
			right_shift(r - 1,n,a);
			break;
		case 4:
			scanf("%d%d",&r,&c);
			island_reversal(r - 1,c - 1,n,a);
			break;
		}
	}

	for(i = 0;i < n;i++){
		for(j = 0;j < n;j++){
			if(j != 0){
				printf(" ");
			}
			printf("%d",a[i][j]);
		}
		printf("\n");
	}

	return 0;
}