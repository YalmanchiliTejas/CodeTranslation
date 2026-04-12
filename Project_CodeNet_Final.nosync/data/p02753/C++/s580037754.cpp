
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <string>
#include <tuple>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <iterator>
#include <random>
#include <cmath>
#include <functional>


using namespace std;
using lint = long long int;



int main() {
	string s;
	cin >> s;

	if (s[0] == s[1] && s[0] == s[2]) {
		cout << "No";
	}
	else {
		cout << "Yes";
	}
}

