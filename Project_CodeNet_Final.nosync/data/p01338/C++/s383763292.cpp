#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;

//// < "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\a.txt" > "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\b.answer"

map<int, int>mp;

int getans(const vector<vector<int>>&field,const int row, const map<vector<int>, int>&memo) {
	if (row == 4) {
		int ans = 0;
		for (auto m : memo) {
			vector<int>changed(m.first);
			int nextscore(m.second);
			for (int j = 0; j < 5; ++j) {
				if (field[row][j]) {
					const int number = (field[row][j] + changed[j]) % 4;
					nextscore += mp[number];
				}
			}
			ans = max(ans, nextscore);
			
		}
		return ans;
	}
	map<vector<int>, int>newmemo;
	for (auto m : memo) {
		for (int i = 0; i < 256; ++i) {
			int num(i);
			vector<int>push(4);
			for (int j = 0; j < 4; ++j) {
				push[j] = num % 4;
				num /= 4;
			}
			vector<int>fliped(5);
			for (int j = 0; j < 4; ++j) {
				fliped[j] += push[j];
				fliped[j + 1] += push[j];
			}
			vector<int>changed(m.first);
			for (int j = 0; j < 5; ++j) {
				changed[j] += fliped[j];
			}
			for (int j = 0; j < 5; ++j)changed[j] %= 4;
			int nextscore(m.second);
			for (int j = 0; j < 5; ++j) {
				if (field[row][j]) {
					const int number = (field[row][j] + changed[j]) % 4;
					nextscore += mp[number];
				}
			}
			newmemo[fliped] = max(newmemo[fliped], nextscore);
		}
	}
	return getans(field, row + 1, newmemo);
	
}

int getans(const vector<vector<int>>field) {
	map<vector<int>, int>amap;
	amap[vector<int>(5, 0)] = 0;
	return getans(field, 0, amap);
}

int main() {
	mp[1] = 0;
	mp[2] = 60;
	mp[3] = 70;
	mp[0] = 80;
	int N; cin >> N;
	while (N--) {
		vector<vector<int>>field(5, vector<int>(5));
		for (int y = 0; y < 5; ++y) {
			for (int x = 0; x < 5; ++x) {
				cin >> field[y][x];
			}
		}
		int ans = getans(field);
		cout << ans << endl;
	}
	return 0;
}