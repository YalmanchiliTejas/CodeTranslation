#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	int num;
	cin >> num;
	vector<int> m(num);
	for (int i = 0; i < num; ++i) {
		cin >> m[i];
	}
	int ans=0,hmax=0;
	for (int i = 0; i < num; i++) {
		if (m[i] >= hmax) {
			ans++;
		}
		hmax = max(hmax, m[i]);
	}
	cout << ans << endl;
	return 0;
}