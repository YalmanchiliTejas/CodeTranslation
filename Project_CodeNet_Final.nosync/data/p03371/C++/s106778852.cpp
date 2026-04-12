#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
typedef long long ll;
using namespace std;

void HalfAndHalf() {
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;
	int AB = C * 2;
	ll res = 0;
	if (AB < A + B ) {
		res += min(X, Y) * AB;
		if (X < Y) {
			int rem = Y - X;
			cout << (res + min(rem * B, AB * rem)) << endl;
		}
		else {
			int rem = X - Y;
			cout << (res + min(rem * A, AB * rem)) << endl;
		}
	}
	else {
		cout << (X * A + Y * B) << endl;
	}

}

int main() {
	HalfAndHalf();
	return 0;
}