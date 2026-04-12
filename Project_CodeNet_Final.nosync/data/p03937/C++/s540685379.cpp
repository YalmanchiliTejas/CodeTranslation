#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int R, C;
char G[15][15];
bool check[15][15];

int main(){
	scanf("%d %d", &R, &C);
	memset(check, true, sizeof(check));
	for(int i=0;i<R;i++){
		scanf("%s", G[i]);
		for(int j=0;j<C;j++){
			if (G[i][j] == '#'){
				check[i][j] = false;
			}
		}
	}
	bool changed = true;
	int posX = 0, posY = 0;
	check[posX][posY] = true;
	if (!check[posX][posY]){
		check[posX][posY] = false;
		changed = false;
	}
	while(changed){
		changed = false;
		while(posX != R-1 && G[posX+1][posY] == '#'){
			posX++;
			check[posX][posY] = true;
			changed = true;
		}
		while(posY != C-1 && G[posX][posY+1] == '#'){
			posY++;
			check[posX][posY] = true;
			changed = true;
		}
	}
	bool ans = true;
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			ans &= check[i][j];
		}
	}
	printf("%s\n", ans?"Possible":"Impossible");
	return 0;
}