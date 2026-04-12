#include<bits/stdc++.h>

using namespace std;

int
main(void){
	int r, c;
	cin >> r >> c;
	vector<vector<pair<char, bool> > >vec(r, vector<pair<char, bool> >(c, make_pair('o', true)));
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			cin >> vec[i][j].first;
		}
	}
	for(int i = 0; i < r; i++){
		bool ch = true;
		for(int j = 0; j < c; j++){
			if(vec[i][j].first == '#')
				ch = false;
		}
		if(ch){
			for(int j = 0; j < c; j++){
				vec[i][j].second = false;
			}
		}
	}
	
	for(int j = 0; j < c; j++){
		bool ch = true;
		for(int i = 0; i < r; i++){
			if(vec[i][j].first == '#')
				ch = false;
		}
		if(ch){
			for(int i = 0; i < r; i++){
				vec[i][j].second = false;
			}
		}
	}
	
	for(int i = 0; i < r; i++){
		bool ch = false;
		for(int j = 0; j < c; j++){
			if(vec[i][j].second == true){
				ch = true;
				cout << vec[i][j].first;
			}
		}
		if(ch) cout << "\n";
	}
}