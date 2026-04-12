#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int main() {
	int n, h, ans = 0, max = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> h;
		if (max <= h) {
			max = h;
			ans++;
		}
	}
	cout << ans << endl;
}