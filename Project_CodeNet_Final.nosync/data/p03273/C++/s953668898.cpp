//abc107_b.cpp
//Sat Aug 25 20:19:28 2018

#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>
#define INTINF 2147483647
#define LLINF 9223372036854775807
using namespace std;
using ll=long long;
typedef pair<int,int> P;

int main(){
	int h,w;
	cin >> h >> w;

	char masu[h][w];
	int draw[h][w];
	for (int i=0;i<h;i++){
		for (int j=0;j<w;j++){
			draw[i][j] = 1;
			masu[i][j] = '.';
		}
	}

	for (int i=0;i<h;i++){
		string temp;
		cin >> temp;
		int flag = 0;
		for (int j=0;j<w;j++){
			if (temp[j] == '.'){
				masu[i][j] = '.';
			}else{
				masu[i][j] = '#';
				flag = 1;
			}
		}
		if (flag == 0){
			for (int k=0;k<w;k++){
				draw[i][k] = 0;
			}
		}
	}

	for (int j=0;j<w;j++){
		int flag = 0;
		for (int i=0;i<h;i++){
			if (masu[i][j] == '#'){
				flag = 1;
			}
		}
		if (flag == 0){
			for (int k=0;k<h;k++){
				draw[k][j] = 0;
			}
		}
	}

	for (int i=0;i<h;i++){
		int flag = 0;
		for (int j=0;j<w;j++){
			if (draw[i][j] == 1){
				cout << masu[i][j];
				flag = 1;
			}
		}
		if (flag == 1){
			printf("\n");
		}
	}
}