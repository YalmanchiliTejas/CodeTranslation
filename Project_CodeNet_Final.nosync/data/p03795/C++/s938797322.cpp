#include <iostream>

using namespace std;

int main()
{
	int n;
	int ans;
	
	cin >> n;
	
	ans = n * 800;
	
	ans -= (n / 15) * 200;
	
	cout << ans << endl;
	
	return (0);
}