#include<iostream>
using namespace std;

int main() {
	int X, Y, Z;
	cin >> X >> Y >> Z;
	cout << (X - Z) / (Y + Z);
	return 0;
}
/*
31536000のコメント解説欄
ここテンプレで用意してるから、A問題とかだとこの先空欄の危険あり

まず、1人座る為には幅Y+両端の2Zが必要
2人座る為にはZYZYZより2Y+3Z
3人座る為にはZYZYZYZより3Y+4Z
以下同様に考えると、n人座る為にはnY+(n+1)Z必要なわけだ
逆に、X>=nY+(n+1)Zより、X-Z>=n(Y+Z)であるから(X-Z)/(Y+Z)>=nとなる
よって(X-Z)/(Y+Z)を端数切り捨てることで答えが求まる
整数型同士での割り算は端数が自動で切り捨てられるので、上の答えでおｋ
*/