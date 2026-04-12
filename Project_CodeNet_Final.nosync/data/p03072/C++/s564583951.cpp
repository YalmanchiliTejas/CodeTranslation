#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	int h;
	int max = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> h;

		if (max <= h) {
			ans++;
			max = h;
		}
	}
	cout << ans << endl;

	return 0;
}