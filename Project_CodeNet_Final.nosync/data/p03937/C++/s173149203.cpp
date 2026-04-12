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
 
int main(){
	int h, w;
	cin >> h >> w;
	vector<int> cnt(h + w - 1, 0);
 
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			char a;
			cin >> a;
			if(a == '#') cnt[i + j]++;
			if(cnt[i + j] > 1){
				cout << "Impossible" << endl;
				return 0;
			}
		}
	}
	cout << "Possible" << endl;
 
	return 0;
}