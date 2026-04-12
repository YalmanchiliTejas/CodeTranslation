#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<numeric>
#include<iomanip>
#include<deque>
#include<tuple>
#include<queue>
#include<map>
#include<cstdint>
#include<unordered_map>
#include<boost/multiprecision/cpp_int.hpp>


#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define F first
#define S second

namespace mp = boost::multiprecision;

using cpp_int = mp::cpp_int;
using ll = long long;
using namespace std;


int main() {
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	int cost = 0;
	if (a + b > c*2) {
		int Min = min(x, y);
		cost += Min *c*2;
		x -= Min  ;
		y -= Min  ;
		//cout << cost << endl;
		if (x == 0) {
			int co = min(b, c * 2);
			cost += co * y;
		}
		else if (y == 0) {
			int co = min(a, c * 2);
			cost += co * x;
		}
	}
	else {
		cost = a * x + b * y;
	}
	cout << cost << endl;
}