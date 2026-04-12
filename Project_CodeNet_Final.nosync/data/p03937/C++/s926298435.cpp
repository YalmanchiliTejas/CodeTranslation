#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<tuple>
#include<iomanip>
#include<map>
#include<queue>
#include<set>
#define int long long
using namespace std;
const int INF = 1e10;
const int ZERO = 0;

signed main() {
	int H,W;
	cin >> H >> W;
	vector<vector<char>> vec(H,vector<char>(W));
	for(int i = 0;i < H;i++) {
		for(int j = 0;j < W;j++) {
			cin >> vec.at(i).at(j);
		}
	}
	int ret = 0;
	for(int i = 0;i < H;i++) {
		for(int j = 0;j < W;j++) {
			if(vec.at(i).at(j) == '#') {
				ret++;
			}
		}
	}
	if(ret == H + W - 1) {
		cout << "Possible" << endl;
	}
	else {
		cout << "Impossible" << endl;
	}
}