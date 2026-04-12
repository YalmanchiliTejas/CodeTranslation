#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	int n;
	cin >> n;
	string str;
	vector<int> alpha('z'-'a'+1,50);
	for (int i = 0; i < n; ++i) {
		cin >> str;
		map<int,int> counter;
		for (int j = 0; j < str.length(); ++j) {
			++counter[(int)str[j]-'a'];
		}

		for (int j = 0; j < ('z'-'a'+1); ++j) {
			alpha[j] = min(alpha[j],counter[j]);
		}
	}
	string res = "";
	for (int i = 0; i < ('z'-'a'+1); ++i) {
		for (int j = 0; j < alpha[i]; ++j) {
			res += (char)('a' + i);
		}
	}
	cout << res << endl;

	return 0;
}
