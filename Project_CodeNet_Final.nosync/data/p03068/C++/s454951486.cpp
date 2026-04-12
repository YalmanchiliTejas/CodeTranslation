#include <algorithm>
#include <iostream>
#include <cstdint>
#include <string>
#include <vector>

using namespace std;

int main() {
	int n, k;
	string s;
	cin >> n;
	cin >> s;
	cin >> k;
	for ( int i = 0; i < n; i++ ) {
		if ( s[i] != s[k-1] ) s[i] = '*';
	}
	cout << s << endl;
	return 0;
}
