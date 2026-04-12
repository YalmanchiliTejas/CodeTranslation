#define _USE_MATH_DEFINES
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <string.h>
#include <math.h>
#include <map>

using namespace std;

int main(){
	int H, W;
	char a[101][101];
	bool b[101][101] = {};
	bool newline[101] = {};
	cin >> H >> W;

	for (int i = 0; i < H; ++i){
		for (int j = 0; j < W; ++j){
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < H; ++i){
		int j = 0;
		for (j = 0; j < W; ++j){
			if (a[i][j] != '.')
				break;
		}
		if (j == W){
			for (j = 0; j < W; ++j){
				b[i][j] = true;
				newline[i] = true;
			}
		}			
	}

	for (int i = 0; i < W; ++i){
		int j = 0;
		for (j = 0; j < H; ++j){
			if (a[j][i] != '.')
				break;
		}
		if (j == H){
			for (j = 0; j < H; ++j){
				b[j][i] = true;
			}
		}
		
	}
	for (int i = 0; i < H; ++i){
		for (int j = 0; j < W; ++j){
			if (b[i][j] != true)
				cout << a[i][j];
		}
		if (newline[i] != true)
			cout << endl;
	}

	return 0;
}