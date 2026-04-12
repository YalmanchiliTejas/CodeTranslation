#include<bits/stdc++.h>
using namespace std;

	
int main(){
	int H, W;
	cin >> H >> W;
	vector<vector<char>> a(H, vector<char>(W));
	for(int i = 0; i < H; i++){
		for(int j = 0; j < W; j++){
			cin >> a.at(i).at(j);
		}
	}
	
	vector<char> jdgLin(H);
	vector<char> jdgCul(W);
	for(int i = 0; i < H; i++){
		bool jdg = true;
		for(int j = 0; j < W; j++){
			if(a.at(i).at(j) != '.'){
				jdg = false;
			}
		}
		if(jdg) jdgLin.at(i) = 'a';
		else jdgLin.at(i) = 'b';
	}
		for(int i = 0; i < W; i++){
		bool jdg = true;
		for(int j = 0; j < H; j++){
			if(a.at(j).at(i) != '.'){
				jdg = false;
			}
		}
		if(jdg) jdgCul.at(i) = 'a';
		else jdgCul.at(i) = 'b';
	}
	
	for(int i = 0; i < H; i++){
		for(int j = 0; j < W; j++){
			if(jdgLin.at(i) == 'b' && jdgCul.at(j) == 'b'){
				cout << a.at(i).at(j);
			}
			if(j == (W - 1)){
				cout << endl;
			}
		}
	}
}