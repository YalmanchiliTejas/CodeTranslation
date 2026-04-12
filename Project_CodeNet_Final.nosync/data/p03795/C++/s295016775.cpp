#include<iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	cout << N * 800 - (N / 15) * 200;
	return 0;
}
/*
31536000のコメント解説欄
ここテンプレで用意してるから、A問題とかだとこの先空欄の危険あり

200円もらえた回数はNを15で割って端数切り捨てた値に等しいので、上の通りになる
*/