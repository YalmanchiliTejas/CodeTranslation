#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <array>
#include <map>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>

using namespace std;
typedef long long int ll;


int main(int argc, char const *argv[])
{
	ll x, y, z;
	cin >> x >> y >> z;
	ll ans = 0;
	x -= z;

	while (x >= y + z)
	{
		ans++;
		x -= y;
		x -= z;
	}
	cout << ans << endl;
}
