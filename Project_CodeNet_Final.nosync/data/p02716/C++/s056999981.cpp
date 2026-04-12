#include <iostream>
#include <bitset>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <deque>
#include <algorithm>
#include <random>
#include <iomanip>

using namespace std;


int main(int argc, char *argv[]) {
	unordered_map<int, unordered_map<int, long long int>> um;
	int n;
	cin >> n;
	int nn = n / 2;
	vector<long long int> v;
	for (int i = 0; i < n; i++) {
		long long int t;
		cin >> t;
		v.push_back(t);
	}

	for (int i = 0; i < n; i++) {
		int l = i, r = n - i - 1;
		int left_rank = nn - r / 2, right_rank = min(nn, l / 2 + 1);
		for (int j = left_rank; j <= right_rank; j++) {
			if (j == 1) {
				um[i][j] = v[i];
			} else {
				bool not_found = true;
				for (int k = 2; k <= 4 && i - k >= 0; k++) {
					if (um[i - k].find(j - 1) != um[i - k].end()) {
						if (not_found) {
							not_found = false;
							um[i][j] = um[i - k][j - 1] + v[i];
						} else {
							um[i][j] = max(um[i][j], um[i - k][j - 1] + v[i]);
						}
					}
				}
			}
		}
	}

	long long int res = -2 * (1e14);
	for (int i = 0; i < n; i++) {
		if (um[i].find(nn) != um[i].end()) {
			res = max(res, um[i][nn]);
		}
	}
	cout << res << endl;
}
