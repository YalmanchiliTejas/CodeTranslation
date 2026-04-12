#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
	int h[25];
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
	}
	int ans = 0;
	int ok = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if(h[j] <= h[i]) ok++;
		}
		if (ok == i)ans++;
		ok = 0;
	}
	cout << ans << endl;
}