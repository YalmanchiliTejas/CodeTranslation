#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <string> //C++
#include <iostream> //C++
#include <vector> //C++
#include <algorithm> //C++
using namespace std; //C++

//C++で提出


// cin >>n;     scanf(入力)
// cout <<k;    printf(出力)
// cout <<k<<endl;   (kを出力して改行)
// string s="AAA";    s.size() =3    (sのサイズ)
// vector <int> a;  配列a(サイズは0)
// a.push_back(10); 配列のサイズが一つ増えて一番後ろに10を代入
// A.pop_back();  最後の要素が消去される
// A.begin() 　配列Aの最初の要素　
// sort(A.begin(),A.end());  配列Aの最初の要素から最後の要素(/.)までを小さい順に並び替えてa[0]から代入していく
// reverse(A.begin(),A.end());  配列Aの最初の要素から最後の要素(/.)までを逆の順にしてa[0]から代入していく
// s.substr(3,2)  配列s[3]から2個の文字を抜き出した文字列 (s[3]とs[4])



int main()
{
	string s;

	cin >> s;

	for (int i = 0; i < s.size() - 1; i++) {
		if (s.substr(i, 2) == "AC") {
			cout << "Yes";
			return 0;
		}
	}

	cout << "No";
	return 0;



	


}




