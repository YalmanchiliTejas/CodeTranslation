#include <bits/stdc++.h>
using namespace std;

int main() {

	int H, W;
	cin >> H >> W;
	
	vector<vector<char>> A(H+1, vector<char>(W+1, '1'));

	for(int i =1;i <= H; i++){
		for(int j =1;j <= W; j++)
			cin >> A.at(i).at(j);
	}

	for(int i = 1;i <= H; i++){
		for(int j = 1;j<= W; j++){
			if(A.at(i).at(j) == '#'){
				A.at(i).at(0) = '0'; //消せない行のフラグ 				
				A.at(0).at(j) = '0'; //消せない列のフラグ 				
				continue;
			}
		}
	}

	for(int i = 1;i <= H; i++){
		if(A.at(i).at(0) == '0'){
			for(int j = 1;j<= W; j++){
				if(A.at(0).at(j) == '0') cout << A.at(i).at(j);
				if(j == W) cout << endl;
				}
			}
		}
	}
