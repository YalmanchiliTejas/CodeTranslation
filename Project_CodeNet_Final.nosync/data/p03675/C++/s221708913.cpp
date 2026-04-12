#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> nums(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	vector<int> res(n, 0);
	int index = 0;
	for (int i = n - 1; i >= 0; i -= 2) {
		res[index] = nums[i];
		if (i >= 1) {
			res[n - 1 - index] = nums[i - 1];
		}
		index++;
	}
	for (int i = 0; i < n; i++) {
		cout << res[i] << " ";
	}
}