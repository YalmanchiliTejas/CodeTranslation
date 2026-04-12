
// A - RGB Cards

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	int r, g, b;
	cin >> r >> g >> b;

	string ans;

	if ((100*r + 10*g + b) % 4 == 0) ans = "YES";
	else ans = "NO";

	cout << ans << endl;

	return 0;
}