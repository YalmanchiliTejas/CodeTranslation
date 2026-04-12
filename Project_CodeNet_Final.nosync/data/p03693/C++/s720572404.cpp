#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

int main()
{
	int32_t r, g, b;
	cin >> r >> g >> b;

	int32_t num = r * 100 + g * 10 + b;

	cout << (num % 4 == 0 ? "YES" : "NO") << endl;

	return 0;
}
