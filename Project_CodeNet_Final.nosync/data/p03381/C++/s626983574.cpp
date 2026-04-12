#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef pair<long long int, long long int> P;

int main() {
	long long int n;
	cin >> n;
	vector<P> x(n);
	for (long long int i = 0; i < n; i++) {
		cin >> x[i].first;
		x[i].second = i;
	}
	sort(x.begin(), x.end());
	long long int m = n / 2;
	vector<P> x2(n);
	for (long long int i = 0; i < n; i++) {
		if (i < m) {
			x2[i].second = x[m].first;
		}
		else {
			x2[i].second = x[m-1].first;
		}
		x2[i].first = x[i].second;
		//cout << x2[i].first << ' ' << x2[i].second << endl;
	}
	sort(x2.begin(), x2.end());

	for (long long int i = 0; i < n; i++) {
		cout << x2[i].second << endl;
	}
	return 0;
}