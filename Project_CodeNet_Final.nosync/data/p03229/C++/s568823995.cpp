#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdint>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int64_t> aa;
	for(int i = 0; i < n; ++i) {
		int64_t t;
		cin >> t;
		aa.push_back(t);
	}
	sort(aa.begin(), aa.end());
	int64_t sum = 0;
	if(n % 2 == 0) {
		for(int i = 0; i < n; ++i) {
			if(i < n / 2 - 1) {
				sum -= aa[i] * 2;
			} else if (i == n / 2 - 1) {
				sum -= aa[i];
			} else if (i == n / 2) {
				sum += aa[i];
			} else {
				sum += aa[i] * 2;
			}
		}
	} else {
		for(int i = 0; i < n; ++i) {
			if(i < (n - 3) / 2) {
				sum -= aa[i] * 2;
			} else if(i > (n + 1) / 2) {
				sum += aa[i] * 2;
			}
		}
		sum += max(
				2 * aa[(n+1)/2] - aa[n/2] - aa[n/2-1],
				    aa[(n+1)/2] + aa[n/2] - aa[n/2-1] * 2);
	}

	cout << sum << endl;
	return 0;
}
