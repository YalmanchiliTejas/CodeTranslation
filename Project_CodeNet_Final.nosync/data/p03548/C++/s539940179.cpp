#include <iostream>

using namespace std;

int main()
{
	int a, b, c;
	int ans = 0;
	
	cin >> a >> b >> c;
	
	a -= b + 2 * c;
	ans++;
	
	ans += a / (b + c);
	
	cout << ans << endl;
	
	return (0);
}