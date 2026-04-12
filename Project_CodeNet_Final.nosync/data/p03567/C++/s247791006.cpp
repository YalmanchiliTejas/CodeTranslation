#include<iostream>	// 入出力
#include<stdio.h>	// printf()が使える 小数は%fで
#include<math.h>	// 数学の関数
#include<vector>	// 配列
#include<string>	// 文字列
#include<map>		// 連想配列
#include<stack>		// スタック
#include<queue>		// キュー
#include<algorithm> // ソートとか

using namespace std;

using ll = long long;



int main()
{

	string S;

	cin >> S;

	for (int i = 0; i < S.length() - 1; ++i)
	{
		if (S[i] == 'A'&&S[i+1] == 'C')
		{
			cout << "Yes" << endl;
			return 0;
		}
	}
	
	cout << "No" << endl;


	return 0;

}