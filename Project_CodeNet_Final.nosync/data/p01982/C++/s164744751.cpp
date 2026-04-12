
#if 1
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <array>
#include <deque>
#include <algorithm>
#include <utility>
#include <cstdint>
#include <functional>
#include <iomanip>
#include <numeric>
#include <assert.h>
#include <bitset>
#include <list>
#include <cmath>
#include <sstream>

#define all_range(C) std::begin(C), std::end(C)

int n;
int A[55];
bool is_uruu(int x) {
	for (int i = 0; i < n; i++)
	{
		if (x % A[i] == 0) {
			return i % 2 == 0;
		}
	}
	return n%2 == 0;
}

int main()
{
	using std::endl;
	using std::cout;
	using std::cin;

	while (true)
	{
		int l, r;
		cin >> n>>l>>r;
		if (n==0 && l==0 && r == 0) { break; }

		for (int i = 0; i < n; i++)
		{
			cin >> A[i];
		}

		int count = 0;
		for (int i = l; i <= r; i++)
		{
			if (is_uruu(i)) {
				++count;
			}
		}
		//cout << "OUT!!!";
		cout << count << endl;
	}

	return 0;
}
#endif

