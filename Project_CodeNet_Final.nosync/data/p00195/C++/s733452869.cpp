#include <bits/stdc++.h>

using namespace std;


int main() {
	int s1, s2, sum, index;

	while (1) {
		cin >> s1 >> s2;
		if (s1 == 0 && s2 == 0) {
			break;
		}

		index = 0;
		sum = s1 + s2;
		for (int i = 1; i < 5; i++) {
			cin >> s1 >> s2;
			if (s1 + s2 > sum) {
				sum = s1 + s2;
				index = i;
			}
		}
		 
		cout << (char)('A' + index) << " " << sum << endl;
	}
	

	return 0;
}
