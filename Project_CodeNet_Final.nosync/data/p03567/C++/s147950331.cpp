#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include<stack>
#include <unordered_map>

using namespace std;

int abs(int x) { return x < 0 ? -x : x; }

int main() {
	string s;
	cin >> s;
	if (s.find("AC") == -1) {
		cout << "No";
	}
	else {
		cout << "Yes";
	}
	return 0;
}
