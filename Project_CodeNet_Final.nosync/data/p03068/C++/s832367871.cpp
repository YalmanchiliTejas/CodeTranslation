#include <iostream>
#include <map>
#include <cmath>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int n; cin >> n;
	string s; cin >> s;
	int c; cin >> c;
	for (int i = 0; i < n; i++) {
		if (s.at(i) != s.at(c - 1)) {
			s.at(i) = '*';
		}
	}

	cout << s << endl;
}