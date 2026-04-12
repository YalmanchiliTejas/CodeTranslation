#include<bits/stdc++.h>
using namespace std;


int main() {
	
	int h, w;
	cin >> h >> w;
	vector<vector<char>> a(h,vector<char>(w));
	for(auto &i:a){
		for(auto &j:i) cin >> j;
	}
	for(int i=0; i<w; i++){
		bool flg = 1;
		for(int j=0; j<h; j++){
			if(a.at(j).at(i)=='#') flg = 0;
		}
		if (flg){
			for(int j=0; j<h; j++){
				a.at(j).at(i) = '+';
			}
		}
	}
		
	for(int i=0; i<h; i++){
		bool flg = 1;
		for(int j=0; j<w; j++){
			if(a.at(i).at(j)=='#') flg = 0;
		}
		if(flg){
			for(int j=0; j<w; j++){
				a.at(i).at(j) = '+';
			}
		}
	}
	for(auto i:a){
		for(auto j:i){
			if(j!='+') cout << j;
		}
		cout << endl;
	}
	
	
	return 0;
}