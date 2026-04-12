#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string>
#include<vector>
#include<map>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<set>

#define P 1000000007

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<long long> a, l, r;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			l.push_back(a[i]);
		}
		else {
			r.push_back(a[i]);
		}
	}
	if (n % 2 == 0) {
		cout << r[r.size() - 1];
		for (int i = r.size() - 2; i >= 0; i--) {
			cout << " " << r[i];
		}
		for (int i = 0; i < l.size(); i++) {
			cout << " " << l[i];
		}
	}
	else {
		cout << l[l.size() - 1];
		for (int i = l.size() - 2; i >= 0; i--) {
			cout << " " << l[i];
		}
		for (int i = 0; i < r.size(); i++) {
			cout << " " << r[i];
		}
	}
	cout << endl;
	return 0;
}
