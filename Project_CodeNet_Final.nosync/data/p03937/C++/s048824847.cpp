#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<map>
using namespace std;
char a[8][8];
int w=0;
	int h=0;
int se(int p, int q,int r){
	if (p==w-1&&q==h-1){
		return 0;
	}
	else{
		if (a[p + 1][q] == '#'){
			return se(p + 1, q, r + 1);
		}
		else if (a[p][q + 1] == '#'){
			return se(p, q + 1, r + 1);
		}
		else return 1;
	}
}
int main(void){

	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++)a[i][j] = 0;
	}
	int n=0;
	
	int x = 0;
	int c = 0;
	scanf("%d %d", &w,&h);
	for (int i = 0; i < w; i++){
      scanf("%s", a[i]);
	}
	for (int i = 0; i < w; i++){
		for (int j = 0; j < h; j++){
			if (a[i][j] == '#') c++;
		}
	}
	if (c == w + h - 1){
		x = se(0, 0, 0);
	}
	else x = 1;
	if (x == 0)printf("Possible\n");
	else printf("Impossible\n");
	return 0;
}