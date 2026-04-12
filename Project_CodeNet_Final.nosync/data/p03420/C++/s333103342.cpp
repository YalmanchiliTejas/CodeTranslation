#include<iostream>
#include<cstdint>
using namespace std;

const bool DEBUG = false;
int main() {
	int N, K;
	cin >> N >> K;
	int64_t sum = 0;
	for (int b = K + 1;b <= N;b ++) { // 各bについてaが何通りか考える
		sum += N / b * (b - K); // N/a*aまでのbの通り数
		if (N - (N / b * b) >= K) {
			sum += N - (N / b * b) - K + 1; // 残りのbの通り数
		}
		if (DEBUG) { // デバッグ用
			for (int a = 1;a <= N;a ++) {
				if (a % b >= K) cout << "(" << a << "," << b << ")" << endl;
			}
			cout << b << ":" << N / b * (b - K) << "+" << (N - (N / b * b) - K >= 0 ? N - (N / b * b) - K + 1 : 0) << endl;
		}
	}
	if (K == 0) cout << (int64_t)N * N; // コーナーケース
	else cout << sum;
	return 0;
}
/*
31536000のコメント解説欄
ここテンプレで用意してるから、A問題とかだとこの先空欄の危険あり

こういう時は、まずあるbを固定して考える ただしbはKより大きい
その時、aはまずKからb-1までのb-K通りある
あとはN/a*aからa-1までを考えれば終わり
*/