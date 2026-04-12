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
	int N;
	int H[30];
	scanf("%d", &N);
	for (int i = 0; i < N; i++)scanf("%d", &H[i]);

	int count = N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < i; j++)
			if (H[i] < H[j]) {
				count--;
				break;
			}


	printf("%d", count);



}

/*         提出前の確認事項

・デバッグ用の関数は＜＜コメント化＞＞しているか？
・すべての＜＜入力例＞＞は試したか？
・＜＜限界値分析＞＞はしたか？
・＜＜出力の改行＞＞の有無は確認したか？
・文字列の＜＜スペル＞＞は確認したか？
　　　　　　　　↓
	 ＜＜提出先＞＞に注意して提出！！
*/