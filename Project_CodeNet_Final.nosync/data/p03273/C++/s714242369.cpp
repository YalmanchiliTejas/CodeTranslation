#include<bits/stdc++.h>
#pragma warning(disable:4996)
using namespace std;
using ll = long long;
const int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
int main() {	
	int H, W;
	cin >> H >> W;
	vector<vector<char>>v(H,vector<char>(W));
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			
			cin >> v[i][j];
		}
	}
	for (int i = 0; i < v.size(); i++) {
		bool c = true;
		for (int j = 0; j < v[i].size(); j++) {
			//cout << i << j;
			//vector<char>v2 = v[3];
			if (v[i][j] == '#') {
				c = false;
			}
		}
		if (c == true) {
			v.erase(v.begin()+i);
			i--;
		}
	}
	vector<int>memo;
	for (int i = 0; i < W; i++) {
		bool c = true;
		for (int j = 0; j < v.size(); j++) {
			if (v[j][i] == '#') {
				c = false;
			}
		}
		if (c == true) {
			memo.push_back(i);
		}
	}
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			if (memo.size() == 0) {
				cout << v[i][j];
			}
			else {
				bool j_c = true;
				for (int k = 0; k < memo.size(); k++) {
					if (j == memo[k]) {
						//cout << v[i][j];
						j_c = false;
					}
				}
				if (j_c == true) {
					cout << v[i][j];
				}
			}
		}
		cout << endl;
	}
}
