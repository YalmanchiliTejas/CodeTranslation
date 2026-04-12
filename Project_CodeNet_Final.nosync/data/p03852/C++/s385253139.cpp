#include <iostream>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <limits>
#include <numeric>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	char c;
	cin >> c;

	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
	{
		cout << "vowel";
		return 0;
	}

	cout << "consonant";

	return 0;
}
