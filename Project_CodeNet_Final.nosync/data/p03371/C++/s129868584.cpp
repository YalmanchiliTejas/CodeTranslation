//inlclude前用define 
#define _USE_MATH_DEFINES

//include
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstdio>
#include<type_traits>
#include<numeric>
#include<limits>
#include<iomanip>
#include<set>

using namespace std;

//typedef
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<char> VC;

//define
#define INF 100000000
#define NUM 1000000007

int main() {
	long long int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	long long int ans;

	if (a+b<2*c) {
		ans = a * x + b * y;
	}else if (max(x, y) == x) {
		ans = min(c * 2 * y + a * (x - y), c * 2 * max(x, y));
	}else {
		ans = min(c * 2 * x + b * (y - x), c * 2 * max(x, y));
	}

	cout << ans << endl;
	return 0;
}