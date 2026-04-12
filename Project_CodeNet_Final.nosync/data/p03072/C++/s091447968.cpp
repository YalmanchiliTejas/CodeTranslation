#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int>H(n);
	for (int i = 1;i <= n;++i) {
		cin >> H[i];
	}
	int max = 0;
	int ans = 0;
	for (int i = 1;i <= n;++i) {
		if (max <= H[i]) {
			ans++;
			max = H[i];
		}
	}
	cout << ans << endl;
}
