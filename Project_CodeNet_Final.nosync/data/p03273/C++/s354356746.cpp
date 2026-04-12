#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <vector> 
#include <numeric>
#include <cmath>
#include <queue>
#include <iomanip>
#include <functional>

#define CHMAX(a,b) a = std::max(a,b)
#define CHMIN(a,b) a = std::min(a,b)
#define MAXMIN(a,b,c) std::max(a,min(b,c))
#define CHABS(a) a = std::abs(a) 
#define COUT(a) std::cout << a << std::endl
#define CERR(a) std::cerr << a << std::endl
#define FOR(n) for(lli i = 0; i < n; i++)

using namespace std;
using lli = long long int;
using pll = pair<lli, lli>;
using tlll = tuple<lli, lli, lli>;
using vll = vector<lli>;

lli mod197 = 1000000007LL;
lli INF = 10000000000000;

// ax + by = gcd(a,b) 最大公約数
template< typename T >
T extgcd(T a, T b, T& x, T& y) {
	T d = a;
	if (b != 0) {
		d = extgcd(b, a % b, y, x);
		y -= (a / b) * x;
	}
	else {
		x = 1;
		y = 0;
	}
	return d;
}

int main(void) {

	int h, w;
	cin >> h >> w;

	string strs[100] = {};

	for (int i = 0; i < h; i++)
		cin >> strs[i];

	//tate
	for (int i = 0; i < h; i++) {
		if (strs[i].find('#') == string::npos) {
			for (int j = i + 1; j < h; j++) {
				strs[j - 1] = strs[j];
			}
			h--;
			i--;
		}
	}

	//yoko
	for (int i = 0; i < w; i++) {
		bool flag = true;
		for (int j = 0; j < h; j++) {
			if (strs[j][i] == '#')
				flag = false;
		}

		if (flag) {
			for (int j = i + 1; j < w; j++) {
				for (int k = 0; k < h; k++) {
					strs[k][j - 1] = strs[k][j];
				}
			}
			w--;
			i--;
		}
	}


	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {

			cout << strs[i][j];
		}
		cout << endl;
	}




	return 0;
}
