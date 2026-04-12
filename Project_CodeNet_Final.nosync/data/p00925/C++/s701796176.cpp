#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

/*
	計算ミス

	ボブは小学校の児童で、算数があまり得意でない。彼は父親の電卓を見つけ、
	それを使って宿題でズルをしようとした。彼の宿題は掛け算と足し算を含む
	数式を計算することである。もちろん、掛け算は足し算の前に行わなければならないが、
	計算機は式を左から右に計算し、演算子の優先順位を無視する。
	そのため彼の答えは次の二つの計算規則のいずれかの結果となりうる。

		足し算の前に掛け算を行う
		演算子の優先順位を無視して左から右に計算を行う

	彼の答えと数式から、どちらの規則が適用されたを出力するプログラムを書け。

	数式は整数と演算子からなる。全ての整数は一桁、すなわち0から9である。
	演算子は+と*の二種類であり、それぞれ足し算と掛け算を示す。
	以下は数式の例である。
		
		1+2*3+4
	
	この数式を、掛け算を最初に計算する規則によって計算すると、入力例１のように、答えは11になる。
	しかし、左から右に計算する規則によると、答えは入力例２で示されるように、答えは13になるだろう。

	どちらの規則で計算しても同じ結果になる場合もありえ、その場合には
	どちらの規則が適用されたか判別できない。加えて、ボブはたまに計算ミスをする。
	いずれの規則でもボブの答えにならない場合、彼が本当に宿題をしたのは明らかである。

	入力
	入力は二行のテストケースからなる。最初の一行には計算する数式が含まれる。
	数式の文字数は常に奇数であり、17以下である。数式中の奇数番目の文字は0から9までの数字である。
	偶数番目の文字は+か*の演算子である。二行目には0から999999999までの整数が含まれる。
	この整数は最初の行で与えられた数式に対するボブの答えである。

	出力
	以下の４つの文字のうち１つを出力せよ。
	M　掛け算を先に行う規則のみの計算結果がボブの答えになる場合
	L　左から右に行う規則のみの計算結果がボブの答えになる場合
	U　両方の規則の計算結果がボブの答えになる場合
	I　いずれの規則の計算結果もボブの答えにならない場合

*/


int main(void){
	//FILE* fp_in = freopen("data.txt", "r", stdin);
	
	vector< int > num;
	string str;
	int ans;
	getline(cin, str);
	cin >> ans;
	int r[2] = {0, 0};

	// multiplication-first rule
	int tmp = -1;
	for(int i = 0; str.length() > 1 && i < str.length() - 2; i += 2) {
		if( str[i + 1] == '+' ) {
			if( tmp == -1 ) tmp = str[i] - '0';
			else tmp *= ( str[i] - '0' );
			num.push_back( tmp );
			tmp = -1;
		} else {
			if( tmp == -1 ) tmp = str[i] - '0';
			else tmp *= ( str[i] - '0' );
		}
	}

	if( tmp == -1 ) {
		num.push_back( str[ str.length() - 1 ] - '0' );
	} else {
		num.push_back( ( str[ str.length() - 1 ] - '0' ) * tmp );
	}

	//left-to-right rule
	r[1] = str[0] - '0';
	for(int i = 2; i < str.length(); i += 2) {
		if( str[i-1] == '+' ) {
			r[1] += str[i] - '0';
		} else {
			r[1] *= str[i] - '0';
		}
	}

	for(int i = 0; i < num.size(); i++)
		r[0] += num[i];

	if( ans == r[0] && ans == r[1] ) {
		cout << "U" << endl;
	} else if( ans == r[0] && ans != r[1] ) {
		cout << "M" << endl;
	} else if( ans != r[0] && ans == r[1] ) {
		cout << "L" << endl;
	} else if( ans != r[0] && ans != r[1] ) {
		cout << "I" << endl;
	}

	//while(1){}
    return 0;
}