#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> a(12);
	for (int i = 0; i < 12; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	if ((a[0] == a[1] && a[0] == a[2] && a[0] == a[3]) && (a[4] == a[5] && a[4] == a[6] && a[4] == a[7]) && (a[8] == a[9] && a[8] == a[10] && a[8] == a[11])) {
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}
	return 0;
}