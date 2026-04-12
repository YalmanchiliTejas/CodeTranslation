void solve();

int main() {
	solve();
	return 0;
}

//////////////////////////////////////////////////
//////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
#include <limits.h>
#include <complex>
#include <assert.h>
using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef complex<ld> Point;

void solve() {
	int X;
	cin >> X;
	if (X == 3 || X == 5 || X == 7)cout << "YES" << endl;
	else cout << "NO" << endl;
	return;
}