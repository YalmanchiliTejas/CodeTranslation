#define _USE_MATH_DEFINES

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
/////////

typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;

////定数
const int INF = (int)1e9 + 10;
const LL MOD = (LL)1e9 + 7;
const LL LINF = (LL)4e18 + 20;
const LD PI = acos(-1.0);
const double EPS = 1e-9; 
/////////
using namespace::std;
//////////////
bool check(int N) {
	vector<bool> res(3, false);
	vector<int> ter = { 3,5,7 };
	while (N) {
		for (int i = 0; i < 3; ++i) {
			if (N % 10 == ter[i]) { res[i] = true; }
		}
		N /= 10;
	}
	return res[0] && res[1] && res[2];
}
void solve() {
	int N;
	cin >> N;
	
	vector<int> res = { 3,5,7 };
	for (int i = 0; i < 3; ++i) {
		if (res[i] == N) {
			cout << "YES" << endl;
			return;
		}
	}
	cout << "NO" << endl;
}

signed main(void) {
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	std::cout << std::fixed;//小数を10進数表示
	cout << setprecision(16);//小数点以下の桁数を指定//coutとcerrで別	

	solve();
}
