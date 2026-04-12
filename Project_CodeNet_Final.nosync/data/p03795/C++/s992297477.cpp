#include<iostream>
using namespace std;
int main()
{
	//// 整数の入力
	//int a;
	//cin >> a;
	//// スペース区切りの整数の入力
	//int b, c;
	//cin >> b >> c;
	//// 文字列の入力
	//string s;
	//cin >> s;
	//// 出力
	//cout << (a + b + c) << " " << s << endl;


	int N;
	cin >> N;

	cout << (800 * N) - N / 15 * 200;
	return 0;
}