#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <stack>
using namespace std;

int main() {
	string s;
	cin >> s;
	char pre = s[0];
	for (int i = 1; i < 3; i++) {
		if (s[i] != pre) {
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";

}