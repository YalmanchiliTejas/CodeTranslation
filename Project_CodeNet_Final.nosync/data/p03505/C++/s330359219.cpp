#include <bits/stdc++.h>
typedef long long i64;
using std::cout;
using std::endl;
using std::cin;

int main() {
	i64 k, a, b; cin >> k >> a >> b;
	if(a >= k) {
		cout << 1 << endl;
		return 0;
	}
	k -= a;
	a -= b;
	if(a <= 0) {
		cout << -1 << endl;
		return 0;
	}
	
	cout << 1 + (k + a - 1) / a * 2 << endl;
	return 0;
}
