#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
int main() {
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;
	if ((C * 2) >= A + B) {
		cout << (X * A) + (Y * B);
	}
	else if ((C *2 ) < A && (C * 2) < B) {
		cout << (C * 2 * max(X, Y));
	}else{
		int rem = abs(X - Y);
		cout << min((C * 2 * min(X, Y)) + ((X > Y) ? rem * A : rem * B) ,
			(C * 2 * max(X, Y)));
	}

	return 0;
}