#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <math.h>
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, a, b) for(int i = (a); i > (b); --i)
#define SZ(a) a.size()
#define ll long long
#define ull unsigned long long
using namespace std;

int main() {

	ll A;
	ll B;
	ll C;
	ll X;
	ll Y;
	cin >> A >> B >> C >> X >> Y;

	int loop = 0;
	if (X > Y)
		loop = X;
	else {
		loop = Y;
	}
	
	ll min = 5000 * 100010 * 2;
	FOR(i, 0, loop + 1) {
		ll costA = (X - i)*A;
		ll costB = (Y - i)*B;
		if (costA < 0) costA = 0;
		if (costB < 0) costB = 0;

		ll cost = costA + costB + i*2*C;
		
		if (min > cost)	min = cost;
		//cout << "(" << (X - i) << "," << (Y - i) << "," << i*2 << ")"<< " " << cost << endl;
	}

	cout << min << endl;


	system("pause");
	return 0;
}