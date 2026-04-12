#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <queue>
using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef pair<int, int> P;
const int c_INF = 111111111;
const int c_mINF = -111111111;
const int c_YET = -1;
const int c_Dx[4] = { 0,0,1,-1 };
const int c_Dy[4] = { 1,-1,0,0 };



int main() {
	int H,W;
	scanf("%d%d", &H,&W);
	char a[120][120];

	int delW = 0;
	int delH = 0;

	for(int i=0;i<H;i++)
		scanf("%s", &a[i]);
	
	for (int i = 0; i < W; ) {
		int count = 0;
		for (int j = 0; j < H; j++) {
			if (a[j][i] == '.')count++;
		
		}
		if (count == H) {
			for (int j = i; j < W-1; j++)
				for (int k = 0; k < H; k++)
					a[k][j] = a[k][j+1];
			W--;
		}
		else i++;
	}
	
	for (int i = 0; i < H;) {
		int count = 0;
		for (int j = 0; j < W; j++){
			if (a[i][j] == '.')count++;
		}
		if (count == W) {
			for (int j = i; j < H-1; j++)
				for (int k = 0; k < W; k++)
					a[j][k] = a[j+1][k];
			H--;
		}
		else{
			i++;
		}
	}

	for (int i = 0; i < H; i++)	{
		for (int j = 0; j < W; j++)	{
			printf("%c", a[i][j]);
		}
		printf("\n");
	}
}



/*         提出前の確認事項

・デバッグ用の関数は＜＜コメント化＞＞しているか？
・すべての＜＜入力例＞＞は試したか？
・＜＜限界値分析＞＞はしたか？
・＜＜出力の改行＞＞の有無は確認したか？
・文字列の＜＜スペル＞＞は確認したか？
・＜＜解の存在性＞＞は確認したか？
　　　　　　　　↓
	 ＜＜提出先＞＞に注意して提出！！
*/