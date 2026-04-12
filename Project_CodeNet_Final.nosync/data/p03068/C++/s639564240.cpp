#include <iostream>
#include <string>
using namespace std;
int main() {
	int n, k;
	char Ck;
	string s;
	cin >> n >> s >> k;
	Ck = s[k-1];
	for (int i = 0; i < n; i++) {
		if (s[i] != Ck) {
			s[i] = '*';
		}
	}
	cout << s << endl;
	cin >> n;
	return 0;
}