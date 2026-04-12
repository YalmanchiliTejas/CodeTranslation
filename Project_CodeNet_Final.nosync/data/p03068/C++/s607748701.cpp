#include <iostream>

using namespace std;

int main() {
	int n,k;
	cin >> n;
	char s[12];
	cin >> s >> k;
	for (int i = 0; i < n; ++i) {
		if (s[k-1] != s[i]) s[i] = '*';
	}
	
	cout << s << endl;

	return 0;
}