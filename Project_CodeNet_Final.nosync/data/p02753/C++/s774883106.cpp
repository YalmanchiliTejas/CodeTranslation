#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <functional>
#include <numeric>
#include <limits>
#include <iomanip>
#include <queue>
#include <cmath>
#include <math.h>
#include <string>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const long long INF = 1LL << 60;
using pll = pair<long long, long long>;


int main() {

	// 標準入力が早くなる。Cスタイルの入出力とC++スタイルの入出力を混合させてはならない。
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	string S;
	cin >> S;

	int flag = 0;
	if (S.find("A") == string::npos) {
		flag = 1;
	}
	if (S.find("B") == string::npos) {
		flag = 1;
	}

	if (flag == 0) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}
