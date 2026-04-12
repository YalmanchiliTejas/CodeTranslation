#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	int A, B, C;
	int X, Y;
	const int INF = (int)2e9;

	cin >> A >> B >> C >> X >> Y;
	int min_ans = INF;
	int n = 2 * max(X, Y);
	for (int i = 0; i <= n; i += 2) {
		int pa = A * max(X - i / 2, 0);
		int pb = B * max(Y - i / 2, 0);
		int pc = C * i;
		int ans = pa + pb + pc;
		min_ans = min(ans, min_ans);
	}

	cout << min_ans << '\n';
	return 0;
}
