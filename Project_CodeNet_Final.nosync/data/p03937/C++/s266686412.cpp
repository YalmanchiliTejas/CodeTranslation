#include<iostream>
using namespace std;

const int MAX = 10; // H
int main() {
	int H, W;
	string A[MAX];
	cin >> H >> W;
	for (int i = 0;i <= W + 1;++ i) {
		A[0] += '.';
		A[H + 1] += '.';
	}
	for (int i = 1;i <= H;++ i) {
		cin >> A[i];
		A[i] = '.' + A[i] + '.';
	}
	A[0][1] = A[H][W + 1] = '#';
	for (int i = 1;i <= H;++ i) {
		for (int j = 1;j <= W;++ j) {
			if (A[i - 1][j] + A[i][j - 1] < '.' + '#' || A[i + 1][j] + A[i][j + 1] < '.' + '#') { // あり得ない移動
				cout << "Impossible";
				return 0;
			}
		}
	}
	cout << "Possible";
	return 0;
}
/*
31536000のコメント解説欄
ここテンプレで用意してるから、A問題とかだとこの先空欄の危険あり
また、コンテスト後に https://31536000.hatenablog.com/ で解説していると思うので、良かったら読んでねー

この方法で移動したとき、左上と右下を除く任意のマスについて自分より左か上のどちらかと右か下のどちらかに#があり、もう片方に.があるはず
また、左上と右下は隣接2マス中どちらかに#があり、もう片方に.がある
これを判定すれば良い
*/