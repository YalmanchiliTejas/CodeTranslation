#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	int  h,w; cin >> h >> w;
	int hw[h+4][w+5];
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			char c; cin >> c;
			if(c == '.')hw[i][j] = 0;
			else hw[i][j] = 1;
		}
	}
	
	
	for(int i = 0; i < h; i++){
		bool isline = true;
		for(int j = 0; j < w; j++){
			if(hw[i][j] == 1)isline = false;
		}
		if(isline){
			for(int j = 0; j < w; j++){
				hw[i][j] = -1;
			}
		}
	}

	for(int i = 0; i < w; i++){
		bool isline = true;
		for(int j = 0; j < h; j++){
			if(hw[j][i] == 1)isline = false;
		}
		if(isline){
			for(int j = 0; j < h; j++){
				hw[j][i] = -1;
			}
		}
	}

	for(int i = 0; i < h; i++){
		int minuscnt = 0;
		for(int j = 0; j < w; j++){
			if(hw[i][j] != -1)cout << ((hw[i][j] == 1)? "#":".");
			else minuscnt++;
		}
		if(minuscnt != w)cout << endl;
		
	}

}