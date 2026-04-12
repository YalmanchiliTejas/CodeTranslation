#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;

int main() {
	int n;
	while (1) {
		int sum = 0;
		cin >> n;
		if (n == 0) break;

		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];

		sort(a.begin(),a.end());
		for (int i = 1; i < n-1; i++) sum += a[i];
		cout << sum / (n-2) << endl;

	}
}
