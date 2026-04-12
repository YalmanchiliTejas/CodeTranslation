#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#define REP(i,a) for(int i = 0; i < (a); i++)
using namespace std;

int main(){
	int h,w;
	cin >> h >> w;
	char a[h][w];
	bool del_h[h] = {};
	REP(i,h){
		bool black = false;
		REP(j,w){
			cin >> a[i][j];
			if(a[i][j] == '#')black = true;
		}
		if(black == false)del_h[i] = true;
	}
	bool del_w[w] = {};
	REP(i,w){
		bool black = false;
		REP(j,h){
			if(a[j][i] == '#')black = true;
		}
		if(black == false)del_w[i] = true;
	}
	REP(i,h){
		if(del_h[i] == false){
			REP(j,w){
				if(del_w[j] == false)cout << a[i][j];
			}
			cout << endl;
		}
	}
}