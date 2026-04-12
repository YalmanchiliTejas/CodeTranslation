#include <cstdio>
#include <cstring>

// 説明は省略しますが, 以下の行の 1 を 0 に変更することでデバッグ用の展開図などが出力されなくなり, 出力例に合う出力になります.
#define DEBUG 0

int main() {
	/* dice : サイコロの状態を保存
	 * dice[0] : 上の面
	 * dice[1] : West  の面
	 * dice[2] : South の面
	 *
	 *    ／‾‾／
	 *   ／_0__／|
	 *   |     |1|
	 *   |__2_ |／
	 *
	 **/

	int i;

	int dice[3] = {1, 3, 2};

	char input[10]; // 入力を保存する char 型の配列 (文字列はchar型の配列)
	int sum = 1;  // 合計
	int temp; // 一時保存用

	int n; // 指示回数
	
	while (1) {
	scanf("%d", &n);
	if (n == 0) break;
	sum = 1;
	dice[0] = 1;
	dice[1] = 3;
	dice[2] = 2;

	if (DEBUG) printf(" |%d|\n%d|%d|%d\n |%d|\n |%d|\n", 7 - dice[2], 7 - dice[1], dice[0], dice[1], dice[2], 7 - dice[0]);

	for (i=0; i<n; ++i) {
		if (DEBUG) printf("Sum: %d\n", sum);

		// n の回数だけ読み込み・処理を繰り返す
		scanf("%s", input);

		if (strcmp(input, "North") == 0) {
			// 北の場合の処理
			temp = 7 - dice[0]; // 処理後の dice[2] の値
			dice[0] = dice[2];
			dice[2] = temp;
		} else if (strcmp(input, "South") == 0) {
			// 南の場合の処理
			temp = 7 - dice[2]; // 処理後の dice[0] の値
			dice[2] = dice[0];
			dice[0] = temp;
		} else if (strcmp(input, "East") == 0) {
			// 東の場合の処理
			temp = 7 - dice[1]; // 処理後の dice[0] の値
			dice[1] = dice[0];
			dice[0] = temp;
		} else if (strcmp(input, "West") == 0) {
			// 西の場合の処理
			temp = 7 - dice[0]; // 処理後の dice[1] の値
			dice[0] = dice[1];
			dice[1] = temp;
		} else if (strcmp(input, "Right") == 0) {
			// 右の場合の処理
			temp = 7 - dice[2]; // 処理後の dice[1] の値
			dice[2] = dice[1];
			dice[1] = temp;
		} else if (strcmp(input, "Left") == 0) {
			// 左の場合の処理
			temp = 7 - dice[1]; // 処理後の dice[2] の値
			dice[1] = dice[2];
			dice[2] = temp;
		}


		if (DEBUG) printf(" |%d|\n%d|%d|%d\n |%d|\n |%d|\n", 7 - dice[2], 7 - dice[1], dice[0], dice[1], dice[2], 7 - dice[0]);

		sum += dice[0];
	}

	printf("%d\n", sum);
	}

	return 0;
}