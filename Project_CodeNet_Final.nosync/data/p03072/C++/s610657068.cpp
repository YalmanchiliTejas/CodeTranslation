#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	int h[25];
	for(int i = 0; i < n; i++) {
		cin >> h[i];
	}
	bool f[25] = {};
	{
		int a = 0;
		for(int i = 0; i < n; i++) {
			if(a<=h[i]) f[i] = true;
			a = max(a,h[i]);
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		ans += (f[i])?1:0;
	}
	cout << ans << endl;
	return 0;
}
