#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <array>
#include <cmath>
#include <queue>
#include <stack>
#include <numeric>

using namespace std;

int main()
{
	string s;

	cin >> s;

	if (s.at(0) != s.at(1) ||
		s.at(1) != s.at(2) ||
		s.at(0) != s.at(2)) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}