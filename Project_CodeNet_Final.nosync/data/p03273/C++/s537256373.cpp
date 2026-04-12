#define _USE_MATH_DEFINES
#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<math.h>
#include<map>
#include<iomanip>
#include<functional>
#include<limits>
#include <unordered_map>
#include <numeric>
#include <array>
#include <queue>
#include <chrono>
#include <random>
#include <fstream>


using namespace std;
using  ull = unsigned long long int;

#define rep(i,n,m) for(long long int i=n;i<(long long int)(m);i++)
#define INF (1<<29)
#define MD 1000000007




int main() {
	int h, w;
	cin >> h >> w;

	vector<vector<char>>map(h, vector<char>(w));

	bool flag = true;

	vector<vector<bool>>b_map(h, vector<bool>(w, true));


	rep(i, 0, h) {
		flag = true;
		rep(j, 0, w) {
			cin >> map[i][j];
			if (map[i][j] == '#')flag = false;
		}
		if (flag) {
			rep(j, 0, w) {
				b_map[i][j] = false;
			}
		}
	}
	
	rep(i, 0, w) {
		flag = true;
		rep(j, 0, h) {
			if (map[j][i] == '#')flag = false;
		}
		if (flag) {
			rep(j, 0, h) {
				b_map[j][i] = false;
			}
		}
	}

	rep(i, 0, h) {
		flag = false;
		rep(j, 0, w) {
			if (b_map[i][j]) {
				cout << map[i][j];
				flag = true;
			}
		}
		if(flag)cout << endl;
	}






	
	return 0;
}