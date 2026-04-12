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
#include <iterator>
#include <numeric>
#include <bitset>
using namespace std;
typedef long long int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {

	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;
	int money = 0;
	if ((A + B) / 2.0 <= C) {
		money += A * X + B * Y;
	}
	else {
		money += 2 * min(X, Y) * C;
		if (X > Y) {
			money += min(A, 2 * C) * (X - Y);
		}
		else {
			money += min(B, 2 * C) * (Y - X);
		}
	}

	cout << money;
	return 0;
}