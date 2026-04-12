#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<iomanip>
#include<iostream>
#include<numeric>
#include<string>
using namespace std;

long gcd(long x, long y) { if (x > y) { return gcd(y, x); } long r; while (y != 0) { r = x % y; x = y; y = r; }return x; }
long lcm(long x, long y) { return(x / gcd(x, y)) * y; }
//--------------------

int main() {

	long res;
	long A, B, C, X, Y; cin >> A >> B >> C >> X >> Y;

	res = min(A * X + B * Y, C * 2 * max(X, Y));

	if (X > Y) res = min(res, C * 2 * Y + A * (X - Y));
	else       res = min(res, C * 2 * X + B * (Y - X));

	cout << res << endl;
}