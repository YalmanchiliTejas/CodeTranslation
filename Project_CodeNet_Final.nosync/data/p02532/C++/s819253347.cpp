#include<iostream>
#include<vector>
#include<string>

#define     MAX_COUNT_N     100

using namespace std;

int main(){
	vector<char> *pblocks;
	vector<char> popped;
	int n;
	string str;
	int p1,p2;
	char c;
	int i;

	// 山の個数の入力
	cin >> n;

	// 入力のチェック
	if((n <= 0) || (n > ((int)(MAX_COUNT_N)))){
		cerr << "山の個数が正しくありません" << endl;
		return -1;
	}

	// n 個の山を作成
	pblocks = new vector<char>[n];

	// 1回目の命令入力
	cin >> str;

	// 「quit」命令が入力されるまで無限ループ
	while (str != "quit"){
		// 命令による条件分岐
		if(str == "push"){
			// 山番号とブロックの色の入力
			cin >> p1 >> c;
			// 山番号のチェック
			if((p1 <= 0) || (p1 > n)){
				cerr << p1 << "番目の山は存在しません" << endl;
				cerr << "山番号は1から" << n << "までの整数です" << endl;
			}else{
				// p2 = p1 - 1
				p2 = p1 - 1;
				// ブロックを山に積む
				(pblocks + p2) -> push_back(c);
			}
		}else if(str == "pop"){
			// 山番号を入力
			cin >> p1;
			// 山番号のチェック
			if((p1 <= 0) || (p1 > n)){
				cerr << p1 << "番目の山は存在しません" << endl;
				cerr << "山番号は1から" << n << "までの整数です" << endl;
			}else{
				// p2 = p1 - 1
				p2 = p1 - 1;
				// p2 番目の山の一番上のブロックの色を取得
				c = (*(pblocks + p2))[((pblocks + p2) -> size()) - 1];
				// popped 山にその色のブロックを積む
				popped.push_back(c);
				// p2 番目の山の一番上のブロックを削除
				(pblocks + p2) -> pop_back();
			}
		}else if(str == "move"){
			// 山番号を入力
			cin >> p1 >> p2;
			// 山番号のチェック
			if((p1 <= 0) || (p1 > n)){
				cerr << p1 << "番目の山は存在しません" << endl;
				cerr << "山番号は1から" << n << "までの整数です" << endl;
			}else if((p2 <= 0) || (p2 > n)){
				cerr << p2 << "番目の山は存在しません" << endl;
				cerr << "山番号は1から" << n << "までの整数です" << endl;
			}else{
				// p1 番目の山の一番上のブロックの色を取得
				c = (*(pblocks + (p1 - 1)))[((pblocks + (p1 - 1)) -> size()) - 1];
				// p2 番目の山にその色のブロックを積む
				(pblocks + (p2 - 1)) -> push_back(c);
				// p1 番目の山の一番上のブロックを削除
				(pblocks + (p1 - 1)) -> pop_back();
			}
		}else{
			cerr << "「" << str << "」は無効な命令です" << endl;
		}

		// 命令の入力
		cin >> str;
	}

	// 出力
	for(i=0;i < ((int)popped.size());i++){
		cout << popped[i] << endl;
	}

	return 0;
}