#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
using namespace std;

typedef long long ll;



int main() {
	int n; cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++) {
		if (b[i] <= a[n / 2 - 1]) cout << a[n / 2] << endl;
		else cout << a[n / 2 - 1] << endl;
	}
	return 0;
}