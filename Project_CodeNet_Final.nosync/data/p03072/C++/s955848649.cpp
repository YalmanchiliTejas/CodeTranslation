#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#define int long long
using namespace std;
signed main() {
	int n, m = 0, a = 0, sum = 0; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (m <= a) {
			sum++;
			m = a;
		}
	}cout << sum << endl;
}