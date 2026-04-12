#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include <functional>
using namespace std;
int n;
int main() {
	while (cin >> n, n) {
		vector<int> v;
		for (int i = 0; i < n; ++i) {
			int a; cin >> a;
			v.push_back(a);
		}
		sort(v.begin(), v.end());
		int sum = 0;
		for (int i = 1; i < v.size() - 1; ++i) {
			sum += v[i];
		}
		cout << sum/(v.size()-2) << endl;
	}
	
	return 0;
}
