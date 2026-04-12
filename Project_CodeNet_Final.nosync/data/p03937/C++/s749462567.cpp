#include<bits/stdc++.h>
using namespace std;

int main(){
	int h,w;
	cin >> h >> w;
	char c[h][w];
	int sum = 0;
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			cin >>  c[i][j];
			if(c[i][j] == '#')sum++;
		}
	}
	if(sum == h + w - 1)cout << "Possible" << endl;
	else cout << "Impossible" << endl;
	return 0;
}