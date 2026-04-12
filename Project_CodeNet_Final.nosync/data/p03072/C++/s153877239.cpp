#include<iostream>
#include<algorithm>
using namespace std;
int main(void)
{
	int n, h;
	int ans = 0;
	int hmax = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> h;
		if (h >= hmax) {
			hmax = h;
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
