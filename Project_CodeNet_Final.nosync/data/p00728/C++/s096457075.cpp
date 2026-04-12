#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
using namespace std;
typedef unsigned long ulong;

void solve() {
	vector<int> res;
	while (true) {
		int n;
		cin >> n;
		if (n == 0)break;

		vector<int> vec;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			vec.push_back(x);
		}
		sort(vec.begin(), vec.end());
		int sum = 0;
		for (int i = 1; i < n - 1; i++)sum += vec[i];
		res.push_back(sum / (n - 2));
	}
	for (int i = 0; i < res.size(); i++)cout << res[i] << endl;
}

int main()
{
	solve();
	return 0;
}
