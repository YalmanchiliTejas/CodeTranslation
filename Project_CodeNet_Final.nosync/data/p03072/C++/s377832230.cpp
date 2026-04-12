#include <iostream>
#include<algorithm>
#include<vector>
#include<functional>
using namespace std;

int main() {
	int n,temp_highest=0,ans=0;
	cin >> n;
	vector<int> h(n);
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
		if (temp_highest <= h[i]) {
			ans++;
			temp_highest = h[i];
		}
	}

	cout << ans << endl;
	return 0;
}