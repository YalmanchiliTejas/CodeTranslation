#include<iostream>
using namespace std;

const int MAX = 100;
int main() {
	int H, W;
	string a[MAX];
	cin >> H >> W;
	for (int i = 0;i < H;++ i) cin >> a[i];
	bool column[MAX], row[MAX];
	for (int i = 0;i < H;++ i) {
		column[i] = false;
		for (int j = 0;j < W;++ j) column[i] |= a[i][j] == '#';
	}
	for (int i = 0;i < W;++ i) {
		row[i] = false;
		for (int j = 0;j < H;++ j) row[i] |= a[j][i] == '#';
	}
	for (int i = 0;i < H;++ i) {
		for (int j = 0;j < W;++ j) if (column[i] && row[j]) cout << a[i][j];
		if (column[i]) cout << endl;
	}
	return 0;
}
/*
31536000のコメント解説欄
ここテンプレで用意してるから、A問題とかだとこの先空欄の危険あり
また、コンテスト後に https://31536000.hatenablog.com/ で解説していると思うので、良かったら読んでねー

各行および列に対してその行/列が全て.で構成されているか調べておきます
そして、後は各文字に対して対応する行/列の両方が.で構成されていないなら出力すれば良いです
*/