#include <bits/stdc++.h>
using namespace std;

int main()
{
	int x, y, z; cin >> x >> y >> z;
	
	int ans = 1;
	int tmp = z + y + z;
	while (true) {

		tmp += y + z;

		if (x < tmp) {
			break;
		}
		ans++;

	}

	cout << ans << endl;
	
	return 0;
		
}