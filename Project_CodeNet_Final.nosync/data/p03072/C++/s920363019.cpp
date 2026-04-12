#include<iostream>
using namespace std; // 575

int main() {
	int N, H, high = 0, ans = 0;
	cin >> N;
	for (int i = 0;i < N;++ i) {
		cin >> H;
		if (high <= H) ++ ans;
		high = max(high, H);
	}
	cout << ans;
	return 0;
}
/*
31536000のコメント解説欄
ここテンプレで用意してるから、A問題とかだとこの先空欄の危険あり
また、コンテスト後に https://31536000.hatenablog.com/ で解説していると思うので、良かったら読んでねー

*/