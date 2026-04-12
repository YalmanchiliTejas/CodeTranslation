#include <iostream>

using namespace std;

int main()
{
	int a, b, c;
	string ans;
	cin >> a >> b >> c;
	if ((100 * a + 10 * b + c) % 4 == 0)
		ans = "YES";
	else
		ans = "NO";
	cout << ans <<"\n";
}