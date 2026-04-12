#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	long long k, a, b; cin >> k >> a >> b;
	if (a >= k)cout << "1\n";
	else if (a - b <= 0)cout << "-1\n";
	else {
		long long p = k - a;
		a -= b;
		if (p%a != 0)p += a - (p % a);
		cout << p / a * 2 + 1 << endl;
	}
	return 0;
}