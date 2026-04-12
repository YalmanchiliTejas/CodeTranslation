#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <cstdlib>

using namespace std;

int main(){

	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	int A, B, C, D;

	A = a * x + b * y; //それぞれをそれぞれの個数買う場合

	B = c * x * 2; //a円x枚のピザの方が少ない、かつ同じ数になるまでcを買った方が安い時
	if( y > x ){ //同じ数の時に足さなくていいから条件分岐が必要？？
		B += b * (y - x);
	}

	C = c * y * 2;
	if( x > y ){
		 C += a * (x - y);
	}

	D = max(x,y) * c * 2; // 全部cを買った方が安い時

	cout << min( min(A,B) , min(C,D) ) <<endl;




	return 0;
}

//mokoさんさんのコードを参照したの