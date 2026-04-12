#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int x; cin >> x;
	if (x == 3 || x == 5 || x == 7) cout << "YES" << '\n';
	else cout << "NO" << '\n';
	return 0;
}