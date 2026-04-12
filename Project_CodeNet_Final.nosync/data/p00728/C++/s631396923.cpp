#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int n, data[100];
	while (cin >> n && n) {
		int sum = 0;
		for (int i = 0; i < n; ++i) cin >> data[i];
		sort(data, data + n);
		for (int i = 1; i < n - 1; ++i) sum += data[i];
		cout << sum / (n - 2) << endl;
	}
	return 0;
}
