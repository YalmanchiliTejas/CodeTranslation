#include<iostream>
using namespace std;

int main() {

	char s[21];
	char c;
	int n;
	int l;
	cin >> l;
	cin >> s;
	cin >> n;
	c = s[n-1];
	for (int i = 0; i < l; i++) {
		if (c == s[i]) {
		}
		else
		{
			s[i] = '*';
		}
	}
	cout << s;

	return 0;
}