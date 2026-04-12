#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int h, w;
	cin >> h >> w;
	vector<string> a(h);
	for(int i = 0; i < h;i++){
		cin >> a[i];
	}
	
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			int cb = 0, cf = 0;
			if(a[i][j] == '.') continue;
			if(i > 0){
				if(a[i-1][j] == '#'){
					cb++;
				}
			}
			if(i < h-1){
				if(a[i+1][j] == '#'){
					cf++;
				}
			}
			if(j > 0){
				if(a[i][j-1] == '#'){
					cb++;
				}
			}
			if(j < w-1){
				if(a[i][j+1] == '#'){
					cf++;
				}
			}
			if(i == 0 && j == 0){
				cb = 1;
			}
			if(i == h - 1 && j == w - 1){
				cf = 1;
			}
			if(cb != 1 || cf != 1){
				cout << "Impossible" << endl;
				return 0;
			}
		}
	}
	
	cout << "Possible" << endl;
	
	return 0;
}