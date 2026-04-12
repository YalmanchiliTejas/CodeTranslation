#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <stdio.h>

using namespace std;

//typedefリスト
typedef long long int llint;
typedef vector<int> vint;
typedef vector< vector<int> > vvint;
typedef vector<string> vstr;


int main(void) {
	llint A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;
	llint ans1 = A * X + B * Y;
	llint ans2 = 2*C * min(X, Y);
	if (min(X, Y) == X)ans2 += (Y - X)*B;
	else ans2 += (X - Y)*A;
	llint ans3 = 2 * C*max(X, Y);
	cout << min(ans1, min(ans2, ans3)) << endl;
}
