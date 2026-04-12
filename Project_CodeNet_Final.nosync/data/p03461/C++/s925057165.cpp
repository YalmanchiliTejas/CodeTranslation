
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <array>
#include <cassert>
#include <bitset>
using namespace std;
using LL = long long;

int A, B;
int d[11][11];
bool flag[11][11];
vector<pair<pair<int, int>, int>> out;
map<pair<int, int>, int>tmp;

#define PAPAPAPAPAPA 1

int main(void)
{
	cin >> A >> B;
	for (int i = 0; i < A; ++i) {
		for (int j = 0; j < B; ++j) {
			cin >> d[i][j];
		}
	}
	for (int xk = 0; xk <= 100; ++xk) {
		for (int yk = 0; yk <= 100; ++yk) {
			int small = INT_MIN;
			for (int i = 0; i < A; ++i) {
				for (int j = 0; j < B; ++j) {
					//if (flag[i][j])continue;
					int val = (i + 1) * xk + (j + 1) * yk;
					small = max(small, d[i][j] - val);
				}
			}
			if (small < 0)continue;
			for (int i = 0; i < A; ++i) {
				for (int j = 0; j < B; ++j) {
					int val = (i + 1) * xk + (j + 1) * yk;
					if (small == d[i][j] - val) {
						if (!flag[i][j]) {
							flag[i][j] = true;
							int from = 0 + xk;
							int to = 201 - yk;
							if (tmp.count({ from,to })) {
								tmp[{from, to}] = min(tmp[{from, to}], small);//バグの可能性あり
							}
							else {
								tmp[{from, to}] = small;
							}
							assert(small <= 100);
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < A; ++i) {
		for (int j = 0; j < B; ++j) {
			if (!flag[i][j]) {
				cout << "Impossible\n";
				return 0;
			}
		}
	}
	cout << "Possible\n";
	for (auto tm : tmp) {
		out.push_back(tm);
	}
	out.push_back({ { 202,0 },0 });
	out.push_back({ { 202,101 },0 });
	out.push_back({ { 100,203 },0 });
	out.push_back({ { 201,203 },0 });
	for (int i = 0; i < 100; ++i) {
		out.push_back({ { i,i + 1 },-1 });
		out.push_back({ { i + 101,i + 102 },-2 });
	}
	cout << 204 << " " << (int)out.size() << endl;
	for (auto elm : out) {
		cout << elm.first.first + 1 << " " << elm.first.second + 1 << " ";
#if PAPAPAPAPAPA
		if (elm.second == -1) {
			cout << "X\n";
		}
		else if (elm.second == -2) {
			cout << "Y\n";
		}
		else {
#endif
			cout << elm.second << endl;
#if PAPAPAPAPAPA
		}
#endif
	}
	cout << "203 204\n";
	return 0;
}
