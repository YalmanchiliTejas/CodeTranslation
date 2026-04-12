#include<iostream>

using namespace std;

int main()
{
	int r, b, g;
	cin >> r >> b >> g;
	if ((b * 10 + g) % 4 == 0) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}