#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <array>
#include <vector>
#include <functional>
#include <unordered_map> 
#include <map> 
#include <numeric>
#include <limits>
#include <utility>
#include <queue>
using namespace std;
typedef long long LL;

int main(void) {
	char c;
	cin >> c;
	if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o') {
		cout << "vowel" << endl;
	}
	else {
		cout << "consonant" << endl;
	}
	return 0;
}