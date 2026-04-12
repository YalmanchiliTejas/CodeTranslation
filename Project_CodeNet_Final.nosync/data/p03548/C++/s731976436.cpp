#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;
#define INF 100000000
#define MOD 1000000007

int main()
{
	int x, y, z, ans = 0;
	
	cin >> x >> y >> z;

	x = x - 2 * z;
	
	while (1) {
		x -= y;
		ans++;
		if (x < y + z) {
			break;
		}
		x -= z;
	}
	cout << ans << endl;

	return (0);
}