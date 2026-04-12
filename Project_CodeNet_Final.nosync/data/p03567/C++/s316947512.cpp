#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<iomanip>

using namespace std;

int main(void) {
	string s;
	cin >> s;
	for (int i = 0; i < s.size() - 1; i++) {
		if (s[i] == 'A'&&s[i + 1] == 'C') {
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
	return 0;
}