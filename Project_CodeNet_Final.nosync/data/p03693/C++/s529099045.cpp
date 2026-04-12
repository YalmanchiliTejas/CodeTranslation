#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int r, g, b; cin >> r >> g >> b;
	if((10 * g + b) % 4 == 0)
		cout << "YES";
	else
		cout << "NO";
	cout << endl;
	return 0;
}