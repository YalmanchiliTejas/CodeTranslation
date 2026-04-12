#include <iostream>
#define llint long long

using namespace std;

llint p, q, s, t, y, m;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s >> t;
	cin >> p >> q >> m >> y;
	
	cout << (s^t^y) << endl;
	
	return 0;
}
