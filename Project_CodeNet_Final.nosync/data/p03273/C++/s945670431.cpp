#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main(){
	int h, w;
	cin >> h >> w;
	char a[h][w];
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			cin >> a[i][j];
		}
	}
	bool black_r[h], black_c[w];
	for(int i=0; i<h; i++) black_r[i]=false;
	for(int i=0; i<w; i++) black_c[i]=false;
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			if(a[i][j]=='#') black_r[i]=true;
		}
	}
	for(int j=0; j<w; j++){
		for(int i=0; i<h; i++){
			if(a[i][j]=='#') black_c[j]=true;
		}
	}
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			if(black_r[i]&&black_c[j]){
				cout << a[i][j];
			}
		}
		if(black_r[i]) cout << endl;
	}
	return 0;
}