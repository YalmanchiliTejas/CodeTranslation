#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	long long ans = 0;
	for (int b = K + 1; b <= N; b++) {
		int MAX = (N - K) / b;
		ans += (b - K) * (MAX + 1);
		ans -= max(0, b * (MAX + 1) - N - 1);
		if (K == 0) ans--; //a*0+0
	}
	cout << ans << endl;
}
