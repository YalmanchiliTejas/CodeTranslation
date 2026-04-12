/*
C++ のソースコードのテンプレート
特にAOJ-ITP1に使いやすい
*/
#define _USE_MATH_DEFINES

#include <iostream> // 標準入出力
#include <fstream>  // ファイル入出力
#include <string>   // 文字列関係
#include <vector>   // 可変の配列
#include <cmath>    // 数学系
#include <iomanip>  // streamの書式関係
#include <algorithm>// max関数など

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;        // 要素数が可変のベクトル
using std::fixed;         // ストリームの設定をデフォルトにする
using std::setprecision;  // 引数に小数点以下の桁数を指定することが出来る

int main() {
	string S;

	cin >> S;

	for (size_t i = 0; i < S.length(); i++)
	{
		if (S[i] == 'A' && S[i+1] == 'C')
		{
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;


	return 0;
}
