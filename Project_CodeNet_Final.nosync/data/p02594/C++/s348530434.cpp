#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;
using ull = unsigned long long;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

template<class T> using V = vector<T>;
template<class T> using VV = vector<vector<T>>;

int main() {
	int x;
	cin >> x;
	if (x >= 30) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}
