#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <functional>
using namespace std;

int main(){
	int number, suu, in;
	// result = 整理番号と正解数の対応
	map<int, int> result;
	// rank = 順位表   need to include <functional>
	set<int, greater<int> > rank;

	while (scanf("%d,%d", &number, &suu), number||suu){
		result.insert(std::pair<int, int>(number, suu));
		rank.insert(suu);
	}
	while (cin >> in, !cin.eof()){
		// 整理番号が入力されるのでresultで正解数調べてrankを参照する.

		int place = 0;
		set<int>::iterator it = rank.begin();
		// set<int> rank; のときに
		//   set<int>::reverse_iretator it = rank.rbegin();とする方法もある.

		int thisSuu = result[in];
		// mapは[]使える. 以下は[]じゃなくiterator使う方法.
		// map<int, int>::iterator it_map = result.find(in);
		// int thisSuu = (*it_map).second;

		while (it != rank.end()){
			place++;
			if (thisSuu == *it){
				cout << place << endl;
				break;
			}
			it++;
		}
	}
	return 0;
}