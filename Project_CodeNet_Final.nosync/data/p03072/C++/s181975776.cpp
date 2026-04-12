#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<map>
using namespace std;
int main()
{
	int n, h[101] = {0};
	int ans = 1, i;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> h[i];
	}
	int max = h[0];

	for (i = 1; i < n; i++) {
		if (h[i] >= max ) {
			ans++;
			max = h[i];
		}
	}
	cout << ans << endl;
	return 0;
}