#include <iostream>
#include <iterator>
#include <cstdio>
#include <array>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <algorithm>
#include <numeric>
#include <bitset>
#include <chrono>
#include <functional>

using namespace std;
using lli = long long int;
using ulli = unsigned long long int;

namespace atcoder {
	void judge_outer(bool judge_exp, string ok = "Yes", string ng = "No")
	{
		if (judge_exp) {
			cout << ok << endl;
		}
		else {
			cout << ng << endl;
		}
	}

	int ncr(int left, int right)
	{
		right = min(left - right, right);
		int ans = 1;
		for (int i = 1; i <= right; i++) {
			ans = ans * (left - right + i) / i;
		}
		return ans;
	}

	const int LIMIT = 1000000256;
	const int tenfive = 100100;
}

using namespace atcoder;

int main()
{
	int height, width;
	cin >> height >> width;
	vector<string> grid(height);
	vector<int> pass_number;

	for (int i = 0; i < height; i++) {
		cin >> grid[i];
	}
	for (int x = 0; x < width; x++) {
		int counter = 0;
		for (int y = 0; y < grid.size(); y++) {
			if (grid[y][x] == '.') {
				counter++;
			}
			else {
				break;
			}
		}
		if (counter == height) {
			pass_number.push_back(x);

		}
	}
	
	for (int y = 0; y < grid.size(); y++) {
		
		if (any_of(grid[y].begin(), grid[y].end(), [](char c) {return c == '#'; }))
		{
			for (int x = 0; x < width; x++) {
				if (count(pass_number.begin(), pass_number.end(), x) == 0) {
					cout << grid[y][x];
				}
			}
			cout << endl;
		}
	}

	return 0;
}