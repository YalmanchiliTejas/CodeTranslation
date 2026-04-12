#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    int x, y, z; cin >> x >> y >> z;

	int tmp = z;
	int cnt = 0;
	while (true) {
		tmp += y + z;
		if (x < tmp) {
			break;
		}
		cnt++;
	}
	cout << cnt << endl;
    return 0;
}