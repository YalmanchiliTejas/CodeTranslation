#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <stdint.h>
#include <queue>
#include <bitset>
#include <iomanip>

using namespace std;

#define PI 3.14159265358979323846
#define INF 1e+9
#define DIV_NUM (1000000007)


// ★ 桁DP
// dp[ 決めた桁数 ][ 未満フラグ ] := 総数
// 未満フラグとは
// 　過去に対応する桁より小さい値を入れたことがある → 全ての値を自由に入れられる
// 　過去に対応する桁より小さい値を入れたことが無い → ０以上D以下の値しか入れられない
//　dp[i][j]からの遷移は
//　　for ( int d = 0; d <= ( j ? 9 : D ); ++d )
//　　　dp[ i + 1 ][ j || ( d < D ) ] += dp[ i ][ j ];
//　の様に書ける
//　更新が終わったあと，dp[ L ][ 0 ] + dp[ L ][ 1 ] が答え
//　求めるのが N未満の整数の数だったら dp[ L ][ 0 ] だけ見ればよい

long long dpA[101][2][5];
// dp[決めた桁数][未満フラグ][0でない数を含む数]
int main() {

	string A;
	int K;
	cin >> A >> K;

	int lenA = A.size();
	dpA[0][0][0] = 1;

	for (int i = 0; i < lenA; i++) {
		for (int j = 0; j < 2; j++) {
			int D = A[i] - '0';
			for (int d = 0; d <= (j ? 9 : D); ++d) {
				for (int k = 0; k < K+1; k++) {
					dpA[i + 1][j || (d < D)][k+(d!=0)] += dpA[i][j][k];
				}
			}
		}
	}

	cout << dpA[lenA][1][K] + dpA[lenA][0][K] << endl;


	return 0;
}
