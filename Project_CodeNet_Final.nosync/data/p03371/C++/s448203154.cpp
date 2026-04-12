#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int MAX_N = 2e5 + 10;
int A, B, C, X, Y, ans;

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> A >> B >> C >> X >> Y;
	ans = A * X + B * Y;

	for (int c = 2; c < MAX_N; c += 2)
		ans = min(ans, c * C + max(0, X - c/2) * A + max(0, Y - c/2) * B);

	cout << ans << "\n";
	return 0;
}