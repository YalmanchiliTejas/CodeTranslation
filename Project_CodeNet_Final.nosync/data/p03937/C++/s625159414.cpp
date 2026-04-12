#include<iostream>
using namespace std;

int main(){
	int H,W;
	char a[10][10] = {};
	scanf("%d%d",&H,&W);
	for(int i = 0 ; i < H ; i ++){
		scanf("\n");
		for(int j = 0 ; j < W ; j ++){
			scanf("%c",&a[i][j]);
		}
	}
	
	int cnt = 0;
	for(int i = 0 ; i < H ; i ++){
		for(int j = 0 ; j < W ; j ++){
			if(a[i][j] == '#')cnt ++;
		}
	}
	if(cnt != H+W-1){
		puts("Impossible");
		return 0;
	}
	int x = 0, y = 0;
	while(x != H-1 || y != W-1){
		if(a[x+1][y] == '#')x ++;
		else if(a[x][y+1] == '#')y ++;
		else {
			puts("Impossible");
			return 0;
		}
	}
	puts("Possible");
}

