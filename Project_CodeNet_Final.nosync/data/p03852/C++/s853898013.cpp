#include <iostream>
#include <cmath>
#include <climits>
#include <string>
#include <numeric>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;
using ll = long long;

int main() {
	char c;
	cin >> c;
	if (c == 'a' ||c== 'e' || c=='i' ||c== 'u' || c=='o') {
		cout << "vowel" << endl;
	}
	else {
		cout << "consonant" << endl;
	}
}
