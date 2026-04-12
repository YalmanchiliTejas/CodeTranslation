//inlclude前用define 
#define _USE_MATH_DEFINES

//include
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<type_traits>
#include<numeric>
#include<limits>
using namespace std;
//typedef
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<char> VC;

//grobal変数


int main() {
	int a, b, c, x, y;
	int ans,abcnt;
	cin >> a >> b >> c >> x >> y;
	if (a + b < 2 * c) {
		ans = a * x + b * y;
	}else if (x > y) {
		ans = min(c * y * 2 + a * (x - y), c*x * 2);
	}else{
		ans = min(c * x * 2 + b * (y - x), c*y * 2);
	}
	cout << ans << endl;
	
}

