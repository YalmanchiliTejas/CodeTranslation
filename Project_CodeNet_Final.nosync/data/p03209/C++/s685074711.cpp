#include<iostream>
#include<cstdint>
using namespace std;

int64_t pow2(int64_t X) {
	if (X == 0) return 1;
	if (X == 1) return 2;
	return pow2(X >> 1) * pow2(X >> 1) * pow2(X & 1);
}
int main() {
	int64_t N, X, patty = 0;
	cin >> N >> X;
	for (;N >= 0;-- N, -- X) {
		if (X >= pow2(N + 1) - 1) { // 半分より多い
			patty |= pow2(N);
			X -= pow2(N + 1) - 2;
		}
	}
	cout << patty;
	return 0;
}
/*
31536000のコメント解説欄
ここテンプレで用意してるから、A問題とかだとこの先空欄の危険あり
また、コンテスト後に https://31536000.hatenablog.com/ で解説していると思うので、良かったら読んでねー

まず、レベルLバーガーの枚数を考えてみるか(本題じゃないけど)
枚数をf(x)とする
この時、f(0)=1, f(x)=3+2f(x-1)より、f(x)=2^(x+2)-3
ということでXは最大で2^52-3が考えられるのでオーバーフローとかに注意、あとはO(X)は許されないっぽい

次に、バーガーの規則を考えていこう
まず、試しに5個だけ列挙
P
BPPPB
BBPPPBPBPPPBB
BBBPPPBPBPPPBBPBBPPPBPBPPPBBB
BBBBPPPBPBPPPBBPBBPPPBPBPPPBBBPBBBPPPBPBPPPBBPBBPPPBPBPPPBBBB
さて、これをどう考えるか考えてみよう
まず、全てのバーガーは対称な形をしているので、X≧2^(N+1)-1なら、答えはX-2^(N+1)+1と2^(N+1)-2の時の答え+1と表すことができる
ちなみに2^(N+1)-2の計算後の答えは2^N-1ね
さて、上の操作でまずXが半分を超えることは無くなった
次に、X-1は要するに1個上のバーガーなので、この時の答えが分かれば再帰的に求まる
よって、これを再帰でもメモ化再帰でもすれば求まる
今回は小さいし再帰しようか、O(N)ね
*/