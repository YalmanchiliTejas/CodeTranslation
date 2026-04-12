#define _USE_MATH_DEFINES
#pragma region include

#include <iostream>
#include <iomanip>
#include <stdio.h>

#include <sstream>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <complex>

#include <string>
#include <cstring>
#include <vector>
#include <bitset>

#include <queue>
#include <set>
#include <map>
#include <stack>
#include <list>

#include <ctime>
////
//#include <random>//
#pragma endregion //#include
/////////

#pragma region typedef
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
#pragma endregion //typedef
////定数
const int INF = (int)1e9;
const LL MOD = (LL)1e9 + 7;
const LL LINF = (LL)4e18 + 20;
const LD PI = acos(-1.0);
const double EPS = 1e-9; 
/////////
using namespace::std;
//////////////

void solve() {
	int H, W;
	cin >> H >> W;
	vector<string>S(H);
	
	for (int h = 0; h < H; ++h) {
		cin >> S[h];
	}
	vector<bool> HH(H, false);
	vector<bool> WW(W, false);
	for (int h = 0; h < H; ++h) {
		bool res = true;
		for (int w = 0; w < W; ++w) {
			if ( S[h][w] == '#') {
				res = false;
			}
		}
		HH[h] = res;
	}
	for (int w = 0; w < W; ++w) {
		bool res = true;
		for (int h = 0; h < H; ++h) {
			if (S[h][w] == '#') {
				res = false;
			}
		}
		WW[w] = res;
	}

	for (int h = 0; h < H; ++h) {
		if (HH[h]) continue;
		for (int w = 0; w < W; ++w) {
			if (WW[w]) {
				
			}
			else {
				cout << S[h][w];
			}
		}
		cout << endl;
	}
}

#pragma region main
signed main(void) {
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	std::cout << std::fixed;//小数を10進数表示
	cout << setprecision(16);//小数点以下の桁数を指定//coutとcerrで別	

	solve();
}
#pragma endregion //main()
