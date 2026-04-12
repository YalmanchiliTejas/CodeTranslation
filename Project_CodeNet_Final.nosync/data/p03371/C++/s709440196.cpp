#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

int main() {
	int A, B, C,X,Y;

	cin >> A >> B >> C >> X >> Y;
	
	int ans = numeric_limits<int>::max();
	int x, y, z = 0;
	while (X >= z/2 || Y >= z/2) {
		x = max(X - z / 2, 0);
		y = max(Y - z / 2, 0);
		ans = min(ans, A *x + B * y + C * z);
		z += 2;
	}

	cout << ans << endl;

	return 0;
}