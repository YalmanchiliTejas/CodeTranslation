#include <bits/stdc++.h>
using namespace std;

int main(){
	int H, W;
	cin >> H >> W;
	vector<vector<char>> P(H, vector<char>(W));
	vector<bool> Y(H, false);
	vector<bool> X(W, false);
	
	for(int i = 0; i < H; i++){
		for(int j = 0; j < W; j++){
			cin >> P[i][j];
			if(P[i][j] == '#')Y[i] = true;
		}
	}
	
	for(int j = 0; j < W; j++){
		for(int i = 0; i < H; i++){
			if(P[i][j] == '#')X[j] = true;
		}
	}
	
	for(int i = 0; i < H; i++){
		if(Y[i]){
			for(int j = 0; j < W; j++){
				if(X[j]){
					cout << P[i][j];
				}
			}
			cout << '\n';
		}
	}
}