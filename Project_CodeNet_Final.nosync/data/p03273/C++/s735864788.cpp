//============================================================================
// Name        : abc107.cpp
// Author      : a
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int H,W;
	cin >> H >> W;
	char map[H][W];
	bool empty_row[H],empty_col[W];
	for (int i = 0; i < H; ++i) {
		empty_row[i]=true;
	}
	for (int j = 0; j < W; ++j) {
		empty_col[j]=true;
	}
	for (int i = 0; i < H; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < W; ++j) {
			map[i][j] = s[j];
			if(s[j]=='#'){
				empty_row[i] = false;
				empty_col[j] = false;
			}
		}
	}


	for (int i = 0; i < H; ++i) {
		if(empty_row[i]) continue;
		for (int j = 0; j < W; ++j) {
			if(!empty_col[j]){
				cout << map[i][j];
			}
		}
		cout << endl;
	}


	return 0;
}
