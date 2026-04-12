#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

int main()
{
	char c;
	cin >> c;

	string vowel = "aeiou";
	bool res = false;
	for (size_t i = 0; i < vowel.size(); i++) {
		if (vowel[i] == c) {
			res = true;
			break;
		}
	}
	cout << (res ? "vowel" : "consonant") << endl;

	return 0;
}
