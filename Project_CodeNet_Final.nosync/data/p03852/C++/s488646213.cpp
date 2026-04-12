#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <set>
using namespace std;

#define rep(i, n) for (int i=0; i<int(n); i++)


//ABC049_a
int main() {
	char c;
	cin >> c;

	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
		cout << "vowel" << endl;
	}
	else {
		cout << "consonant" << endl;
	}
}