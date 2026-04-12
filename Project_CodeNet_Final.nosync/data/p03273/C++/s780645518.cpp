#include <bits/stdc++.h>
using namespace std;

int main() {
    int r, c;
    cin >> r >> c;
    
    vector<string> s(r);
    
    for(int i = 0; i < r; i ++){
    	cin >> s[i];
	}
	
	int j;
	int rcount = 0;
	for(int i = 0;i < r; i ++){
		for(j = 0; j < c; j ++){
			if(s[i][j] == '#')
				break;
		}
		if(j == c){
			for(j = 0; j < c; j ++)
				s[i][j] = '=';
		}
	}
	
	for(int i = 0;i < c; i ++){
		for(j = 0; j < r; j ++){
			if(s[j][i] == '#')
				break;
		}
		if(j == r){
			for(j = 0; j < r; j ++){
				s[j][i] = '=';
			}
		}
	}
	
	bool enter = false;
	for(int i = 0;i < r; i ++){
		bool enter = false;
		for(int j = 0; j < c; j ++){
			if(s[i][j] != '='){
				cout << s[i][j];
				enter = true;
			}
		}
		if(enter)
			cout << endl;
	}
}