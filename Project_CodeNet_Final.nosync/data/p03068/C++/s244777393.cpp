#include <iostream>
#include <string.h>
using namespace std;

int main() {
	int n, k;	char s[256];
	cin >> n >> s >> k;
	char sum;

	sum = s[k-1];

	for (int i = 0; i < n; i++) {
		if (s[i] != sum) {
			s[i] = '*';
		}
	}

	cout << s << endl;

	return 0;
}