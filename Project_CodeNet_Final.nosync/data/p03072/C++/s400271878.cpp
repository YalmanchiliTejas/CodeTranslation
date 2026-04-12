#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>
#include <list>
#include <unordered_set>
#include <tuple>
#include <limits>
#include <type_traits>
using namespace std;

using INT = long long;
using UINT = unsigned long long;

unsigned gcd(unsigned a, unsigned b) {
	while (1) {
		if (a < b) swap(a, b);
		if (!b) break;
		a %= b;
	}
	return a;
}

int main()
{
	int N;
	cin >> N;

	int maxH = 0;
	int ans = 0;

	for (size_t i = 0; i < N; i++)
	{
		int h;
		cin >> h;
		if (maxH <= h)
		{
			ans++;
			maxH = h;
		}
	}
	cout << ans << endl;
	return 0;
}
