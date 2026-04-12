#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <functional>
#include <queue>
#include <string>
#include <map>
using namespace std;

long long X, Y, A, B, C, minx = (1LL << 60);
int main() {
	cin >> A >> B >> C >> X >> Y;
	for (int i = 0; i <= max(X, Y); i++) {
		long long Z1 = X - i, Z2 = Y - i, Z3 = 2 * i; Z1 = max(Z1, 0LL); Z2 = max(Z2, 0LL);
		minx = min(minx, A * Z1 + B * Z2 + C * Z3);
	}
	cout << minx << endl;
	return 0;
}