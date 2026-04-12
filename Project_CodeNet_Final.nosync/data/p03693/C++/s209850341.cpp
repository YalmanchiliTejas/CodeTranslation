#include<iostream>	// 入出力
#include<math.h>	// 数学の関数
#include<vector>	// 配列
#include<string>	// 文字列


using namespace std;


int main()
{
	int r, g, b;
	cin >> r >> g >> b;

	if ((r * 100 + g * 10 + b) % 4 == 0) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}


	return 0;
}