#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


int H,W;
char table[105][105];
char work[105][105];

int main(){

	scanf("%d %d",&H,&W);

	for(int row = 0; row < H; row++){

		scanf("%s",table[row]);
	}

	int h = 0;

	//行を抜く
	for(int row = 0; row < H; row++){
		bool FLG = false;
		for(int col = 0; col < W; col++){
			if(table[row][col] == '#'){
				FLG = true;
				break;
			}
		}
		if(FLG){
			for(int col = 0; col < W; col++){

				work[h][col] = table[row][col];
			}
			h++;
		}
	}

	//列を抜く
	int w = 0;
	for(int col = 0; col < W; col++){
		bool FLG = false;
		for(int row = 0; row < h; row++){
			if(work[row][col] == '#'){
				FLG = true;
				break;
			}
		}
		if(FLG){
			for(int row = 0; row < h; row++){

				table[row][w] = work[row][col];
			}
			w++;
		}
	}

	for(int row = 0; row < h; row++){
		for(int col = 0; col < w; col++){
			printf("%c",table[row][col]);
		}
		printf("\n");
	}


	return 0;
}
