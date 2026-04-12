#include <iostream>
#include <string>

using namespace std;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int r, g, b;
	int ans;
	cin >> r >> g >> b;

	ans = r * 100 + g * 10 + b;
	if (ans % 4 == 0) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}

	return 0;
}