#include <iostream>

using namespace std;

int main()
{
	int x,y,z;
	cin >> x >> y >> z;
	
	int ans = 1;
	while(ans*y + (ans+1)*z <= x)
	{
		ans++;
	}
	
	ans--;
	
	cout << ans << endl;
}