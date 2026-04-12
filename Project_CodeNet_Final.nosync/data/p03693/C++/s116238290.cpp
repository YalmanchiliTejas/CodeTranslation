
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <iomanip>
#include <stack>
#include <bitset>
#include <map>

using namespace std;
typedef long long ll;
const ll INF = 1LL << 50;

int solve();

int main(void) {
	while (solve()) {}
	return 0;
}

int solve() {

	int a = 0;
	for (int i = 0; i < 3; i++) {
		int j;
		cin >> j;
		a *= 10;
		a += j;
	}

	if (a % 4 == 0) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	
	return 0;
}