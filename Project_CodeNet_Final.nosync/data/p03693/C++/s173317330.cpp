#include<iostream>
using namespace std;

int main() {
	int r, g, b;
	cin >> r >> g >> b;
	if ((2 * g + b) % 4 == 0) cout << "YES";
	else cout << "NO";
	return 0;
}
/*
31536000のコメント解説欄
ここテンプレで用意してるから、A問題とかだとこの先空欄の危険あり

実際に4の倍数か判定すれば良い
ところで、3桁の整数をxとするとx=100r+10g+b=4(25r+2g)+2g+bになるよね
ここで4(25r+2g)は絶対に4の倍数なので、判定に使うのは2g+bだけで大丈夫だよ
*/