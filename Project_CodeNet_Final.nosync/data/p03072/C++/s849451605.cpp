#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;
using ll = long long;



int main() {
	int n;
	cin >> n;
	vector<int> h(n);
	for (int i = 0; i < n; i++) cin >> h[i];
	int m=0,ans=1;
	m = h[0];
	for (int i = 1; i < n; i++) {
		if (m <= h[i]) ans++;
		m = max(m, h[i]);
	}
	cout << ans << endl;


	return 0;
}