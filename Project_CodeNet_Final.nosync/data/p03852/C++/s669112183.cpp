#include <iostream>
#include <numeric>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <math.h>
#include <cmath>
#include <set>   

using namespace std;


int main() {

	string s;

	cin >> s;

	if (s == "a" || s == "i" || s == "u" || s == "e" || s == "o") {
		cout << "vowel" << endl;
	}
	else {
		cout << "consonant" << endl;

	}
}

