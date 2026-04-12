#include <iostream>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <limits>
#include <algorithm>
#include <functional>

#include <map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string S;
	cin >> S;

	map<char, int> info;

	for (char ch : S)
	{
		info[ch]++;
	}

	if (info['A'] == 3 || info['B'] == 3)
	{
		cout << "No";
		return 0;
	}

	cout << "Yes";

	return 0;
}