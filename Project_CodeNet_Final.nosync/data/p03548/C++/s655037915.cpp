
// B - ISU

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	int X, Y, Z;
	cin >> X >> Y >> Z;

	int ans = 0;
	int need = Z;
	while (1) {
		need += Y + Z;
		if (need > X) break;
		ans++;
	}

	cout << ans << endl;

	return 0;
}