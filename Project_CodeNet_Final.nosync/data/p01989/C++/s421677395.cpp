#include <iostream>
#include <string>
#include <bitset>
using namespace std;

int main() {
	string S; cin >> S;
	int n = (int)S.size();
	int res = 0;
	for (int bit = 0; bit < (1 << (n - 1)); ++bit) {
		bool ok = true;
		int tmp = 0, num = 0;
		bool leading_zero = false;
		int div = 0;
		for (int i = 0; i < n; ++i) {
			if (num == 0 && S[i] == '0') leading_zero = true;
			tmp = tmp * 10 + (int)(S[i] - '0');
			++num;
			if ((bit & (1 << i)) || i == n-1) {
				if (leading_zero && num > 1) ok = false;
				if (tmp < 0 || tmp > 255) ok = false;
				tmp = num = 0;
				++div;
			}
		}
		if (ok && div == 4) ++res;
	}
	cout << res << endl;
}
