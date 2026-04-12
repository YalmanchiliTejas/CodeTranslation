#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <tuple>
#include <utility>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
const int INF = 1000000000;
const int MOD = 1000000007;
int main(){
	int h,w;
	cin >> h >> w;
	vector<string> grid(h);
	for(int i = 0;i < h;i++)cin >> grid[i];

	vector<vector<bool>> gf(h,vector<bool>(w,false));
	for(int i = 0;i < h;i++){
		bool flag = true;
		for(int j = 0;j < w;j++){
			if(grid[i][j] == '#')flag = false;
		}
		if(flag){
			for(int j = 0;j < w;j++)gf[i][j] = true;
		}
	}

	for(int j = 0;j < w;j++){
		bool flag = true;
		for(int i = 0;i < h;i++){
			if(grid[i][j] == '#')flag = false;
		}
		if(flag){
			for(int i = 0;i < h;i++)gf[i][j] = true;
		}
	}

	for(int i = 0;i < h;i++){
		bool flag = false;
		for(int j = 0;j < w;j++){
			if(!gf[i][j]){
				cout << grid[i][j];
				flag = true;
			}
		}
		if(flag)cout << endl; 
	}
}
