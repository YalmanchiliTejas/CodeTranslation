#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <climits>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>

#define DIV 1000000007

using namespace std;

long long H, W;
bool ban[10][10];

bool valid(int y, int x){
	return (y>=0 && y < H && x  >= 0 && x < W);
}


int main(){
	cin >> H >> W;
	for(int i = 0; i < H; i++){
		for(int j = 0; j < W; j++){
			char tmp;
			cin >> tmp;
			if(tmp == '#'){
				ban[i][j] = true;
			}
		}
	}

	int curx = 0;
	int cury = 0;

	while(1){
		ban[cury][curx] = false;
		if(valid(cury + 1, curx) && ban[cury+1][curx]){
			cury++;
		}else if(valid(cury, curx+1) && ban[cury][curx+1]){
			curx++;
		}else{
			break;
		}
	}

	for(int i = 0; i < H; i++){
		for(int j = 0; j < W; j++){
			if(ban[i][j]){
				cout << "Impossible" << endl;
				return 0;
			}
		}
	}

	cout << "Possible" << endl;
	return 0;


}

