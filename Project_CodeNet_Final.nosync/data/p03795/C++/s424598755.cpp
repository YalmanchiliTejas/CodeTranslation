
// A - Restaurant

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	int N;
	cin >> N;

	int x = 800 * N;
	int y = (N / 15) * 200;

	int ans = x - y;

	cout << ans << endl;

	return 0;
}