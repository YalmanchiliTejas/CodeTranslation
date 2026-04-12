#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
#define H 105
#define W 105

int main() {
	int h,w;
	char masu[H][W];
	cin >> h >> w;
	//表示させるなら1させないなら0
	int ans[H][W] = {};

	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			cin >> masu[i][j];
		}
	}

	for (int i = 0; i < h; ++i) {
		//seiは横一列すべて同じならtrue
		bool sei = true;
		for (int j = 0; j < w; ++j) {
			if(masu[i][j] == '#') {
				sei = false;
				break;
			}
		}
		if(sei == true)
			for (int j = 0; j < w; ++j)
			{
				ans[i][j] = 1; 
			}
	}
	for (int j = 0; j < w; ++j) {
		//seiは横一列すべて同じならtrue
		bool sei = true;
		for (int i = 0; i < h; ++i) {
			if(masu[i][j] == '#') {
				sei = false;
				break;
			}
		}
		if(sei == true)
			for (int i = 0; i < h; ++i)
			{
				ans[i][j] = 1; 
			}
	}
	for (int i = 0; i < h; ++i)
	{
		int counter = 0;
		for (int j = 0; j < w; ++j)
		{
			if(ans[i][j] == 0)
			{
				cout << masu[i][j];
				counter++;
			}
		}
		if(counter != 0)
			cout << endl;	
	}

	return 0;
}