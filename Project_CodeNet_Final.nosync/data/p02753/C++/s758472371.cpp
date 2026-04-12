#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <vector>
#include <map>
#include <set>
#include <regex>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

int main() {
	set<char> s;
	copy_n(istream_iterator<char>(cin), 3, inserter(s, s.end()));
	cout << (s.size() == 2 ? "Yes" : "No") << endl;
	return 0;
}
