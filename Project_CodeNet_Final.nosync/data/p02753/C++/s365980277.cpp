#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <math.h>
#include <stdlib.h>

typedef long double ld;
typedef long long ll;

using namespace std;

int main() {
	string s;
	cin >> s;
	for (int i = 0; i < 2; i++) {
		if (s[i] != s[i + 1]) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No";
	return 0;
}
