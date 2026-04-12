#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <string>
#include <sstream>
#include <algorithm>
#include <random>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cassert>
#include <climits>
#include <thread>

#define FOR_LT(i, beg, end) for (int i = beg; i < end; i++)
#define FOR_LE(i, beg, end) for (int i = beg; i <= end; i++)

using namespace std;

int main()
{
	int n; cin >> n;
	vector<int> hs(n);
	for (auto& h : hs) {
		cin >> h;
	}

	int sum = 0;
	FOR_LT(i, 0, n) {
		bool is_ok = true;
		FOR_LT(j, 0, i) {
			if (hs[j] > hs[i]) {
				is_ok = false;
				break;
			}
		}
		if (is_ok) sum++;
	}

	cout << sum << endl;

	return 0;
}