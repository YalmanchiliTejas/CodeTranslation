#include <iostream>
#include <stdio.h>
#include <math.h> 
#include <algorithm>
#include <numeric>
#include <functional>
#include <vector>
#include <string>
#include <numeric>
#include <bitset>
#include <queue>

using namespace std;
vector<string> area;

int main() {
	//input
	int h, w;
	cin >> h >> w;

	int h2, w2;
	h2 = h; 
	w2 = w;

	for (int i = 0; i < h; ++i) {
		string tmp;
		cin >> tmp;
		area.push_back(tmp);
	}
	//cout << area.at(0)[0] << endl;

	//横消す
	int i = 0;
	for (i = 0; i < h; ++i) {
		int h_cnt = 0;
		for (int j = 0; j < w; ++j) {
			
			if (area.at(i)[j] == '.') {
				h_cnt++;
			}
		}
		if (h_cnt == w) {
			//消す
			area.erase(area.begin() + i);
			i = -1; //縦のカウンタのリセット
			h--;
		}

	}

	//縦を消す
	//削除条件の確認
	vector<int> tmp;
	for (int i = 0; i < w; ++i) {
		int w_cnt = 0;
		for (int j = 0; j < h; ++j) {
			if (area.at(j)[i] == '.'){
				w_cnt++;
			}
		}
		if (w_cnt == h) {
			tmp.push_back(i);
		}
	}

	//消す
	int i2 = 0;
	vector<int> tmp2;
	tmp2 = tmp;

	int tmpcnt = 0;
	for (int i2 = 0; i2 < h; ++i2) { //縦一列分
		tmpcnt++;
		for (int j = 0; j < tmp2.size(); ++j) {
			area.at(i2).erase(area.at(i2).begin() + tmp2.at(j));
			tmp2.erase(tmp2.begin() + j);
			//要素内を引く1する
			for (int m = 0; m < tmp2.size(); ++m) {
				tmp2.at(m) = tmp2.at(m) - 1;
			}
			j = -1;
		}
		tmp2 = tmp;
		w--;
	} //縦一列分


	for (int i = 0; i < area.size(); ++i) {
		for (int j = 0; j < area.at(i).size(); ++j) {
			cout << area.at(i)[j];
		}
		cout << endl;
	}

	return 0;
}