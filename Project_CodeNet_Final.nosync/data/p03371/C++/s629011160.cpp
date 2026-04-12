#include<iostream>
#include<algorithm>
using namespace std;
using LL =long long;

int main() {
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;
	LL ans = 1e10;
	for (int z = 0; z <= 2 * max(X, Y); z += 2) {
		LL sum = A * max(X - z / 2, 0) + B * max(Y - z / 2, 0) + C * z;
		ans = min(sum, ans);

	}


	cout << ans << endl;
	return 0;
}