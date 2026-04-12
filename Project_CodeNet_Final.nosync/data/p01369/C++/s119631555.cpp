#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main ( void ){
	//左手で打つ文字列
	string left = "qwertasdfgzxcvb";
	//入力文字列変数
	string inputs;
	while(1){
		//入力文字列の取得
		cin >> inputs;
		//端末処理
		if(inputs.at(0)=='#') break;
		//打った手を保持するスタック
		stack<char> seq;
		//打ち替え回数保持変数
		int cnt=0;
		//入力文字列を先頭から１文字ずつ走査
		for( int i=0;i<inputs.length();i++){
			//左手か右手か保持するchar変数
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