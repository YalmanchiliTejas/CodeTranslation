#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;

int main() {
	int N, A, a = 0, ans = INT_MAX;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> A;
		a += A;
		ans = min(a / (1 + i), ans);
	}
	cout << ans << endl;
}
