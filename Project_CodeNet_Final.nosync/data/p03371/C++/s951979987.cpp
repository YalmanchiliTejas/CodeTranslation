#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

int main()
{
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;

	int ans = numeric_limits<int>::max();
	for (int n_AB = 0; n_AB / 2 <= max(X, Y); n_AB += 2) {
		int n_A = max(0, X - n_AB / 2);
		int n_B = max(0, Y - n_AB / 2);
		int total = n_A * A + n_B * B + n_AB * C;
		ans = min(ans, total);
	}
	cout << ans << endl;
}
