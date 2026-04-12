#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	int H, W;
	cin >> H >> W;
	char a[H][W];
	int cnt_r[H], cnt_c[W];
	for(int j = 0; j < W; j++){
		cnt_c[j] = 0;
	}
	for(int i = 0; i < H; i++){
		cnt_r[i] = 0;
		for(int j = 0; j < W; j++){
			cin >> a[i][j];
			if(a[i][j] == '#'){
				cnt_r[i]++;
				cnt_c[j]++;
			}
		}
	}
	//cout << endl;
	for(int i = 0; i < H; i++){
		if(cnt_r[i] != 0){
			for(int j = 0; j < W; j++){
				if(cnt_c[j] != 0){
					cout << a[i][j];
				}
			}
			cout << endl;
		}
	}
	return 0;
}