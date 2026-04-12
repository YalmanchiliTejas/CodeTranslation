#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main ( void ){
	string left = "qwertasdfgzxcvb";
	string inputs;
	while(1){
		cin >> inputs;
		if(inputs.at(0)=='#') break;
		stack<char> seq;
		int cnt=0;
		for( int i=0;i<inputs.length();i++){
			char pos;
			//文字列が左手で打つなら posにr 左手なら l
			if(left.find(inputs.at(i))!=-1)	pos='r';
			else pos='l';
			//最後に打った手がposと違うならカウントアップ
			if(seq.size()!=0 && seq.top()!=pos)	cnt++;
			//スタックに今打った手を積む
			seq.push(pos);
		}
		//結果の出力
		cout << cnt << endl;
	}
}