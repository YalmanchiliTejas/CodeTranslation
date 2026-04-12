#include <cstring>
#include <sstream>
#include <iostream>
using namespace std;

string fizzbuzz(int x) {
	if (x % 15 == 0) return "FizzBuzz";
	if (x % 5 == 0) return "Buzz";
	if (x % 3 == 0) return "Fizz";
	ostringstream os;
	os << x;
	return os.str();
}

int main () {
	int n, m;
	while (cin >> m >> n, n || m) {
		int alive = m;
		bool fail[m];
		memset(fail, 0, sizeof(fail));
		int p = 0;
		for (int i = 0; i < n; i++) {
			string str;
			cin >> str;
			if (alive == 1) continue;
			if (str != fizzbuzz(i + 1)) {
				fail[p] = true;
				alive--;
			}
			do {
				p = (p + 1) % m;
			} while (fail[p]);
		}
		bool first = true;
		for (int i = 0; i < m; i++) {
			if (fail[i]) continue;
			if (first) first = false;
			else {
				cout << ' ';
			}
			cout << i + 1;
		}
		cout << endl;
	}
	return 0;
}