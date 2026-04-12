#include <bits/stdc++.h>

using namespace std;

int main() {
	string str;
	cin >> str;
	int a = 0, b = 0;
	for (int i = 0; i < 3; i++) {
		if (str[i] == 'A') {
			a++;
		} else {
			b++;
		}
	}
	if (a >= 1 && b >= 1) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	return 0;
}