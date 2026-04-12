#include <iostream>
#include <vector>
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <limits>

using namespace std;

int main (int argc, char* argv[]) {
	int n;
	cin >> n;
	int max_h = 0;
	int res = 0;
	for (int i = 0; i < n; i++) {
		int h;
		cin >> h;
		if (h >= max_h) {
			res++;
		}
		max_h = max(max_h, h);
	}
	cout << res << endl;
}
