#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(void){
	int h,w;
	cin >> h >> w;
	vector<string> s(h);
	for(int i = 0; i < h; ++i){
		cin >> s[i];
	}
	for(int i = 0; i < h; ++i){
		int count = 0;
		for(int j = 0; j < w; ++j){
			if(s[i][j]=='.')count++;
		}
		if(count == w){
			for(int j = 0; j < w; ++j){
				s[i][j]='d';
			}
		}
	}
	for(int j = 0; j < w; ++j){
		int count = 0;
		for(int i = 0; i < h; ++i){
			if(s[i][j] == '.' || s[i][j] == 'd')count++;
		}
		if(count == h){
			for(int i = 0; i < h; ++i){
				s[i][j]='d';
			}
		}
	}
	for(int i = 0; i < h; ++i){
		int count = 0;
		for(int j = 0; j < w; ++j){
			if(s[i][j] != 'd'){
				cout << s[i][j];
				count++;
			}

		}
		if(count != 0){
			cout << endl;
		}
	}
	return 0;
}