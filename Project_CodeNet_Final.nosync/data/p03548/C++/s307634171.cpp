#include "bits/stdc++.h"
using namespace std;
int main() {
	long long X, Y, Z;
	cin >> X >> Y >> Z;
	int ans = 0, bet = 1;
	while (ans * Y + bet * Z <= X) {
		ans++;
		bet++;
	}
	ans--;
	cout << ans << endl;
}