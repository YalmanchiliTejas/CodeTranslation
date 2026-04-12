#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n;
string S[55];

int c[30];

int main(void) {

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> S[i];
	}

	for (int k = 0; k < 26; k++) {
		c[k] = 99;
		for (int i = 1; i <= n; i++) {
			int count = 0;
			for (int j = 0; j < (int)S[i].size(); j++) {
				if (S[i][j] - 'a' == k) { count++; }
			}
			c[k] = min(c[k], count);
		}
	}

	string ans="";

	for (int k = 0; k < 26; k++) {
		for (int i = 0; i < c[k]; i++) {
			char tmp = 'a' + k;
			
			ans += tmp;
		}
	}

	cout << ans << endl;

	//system("pause");
	return 0;
}