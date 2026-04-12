#include <iostream>
#define llint long long

using namespace std;

llint a, b, c;
llint x, y;

int main(void)
{
	cin >> a >> b >> c >> x >> y;
	
	llint ans = 1e18;
	for(int i = 0; i <= max(x, y); i++){
		ans = min(ans, 2*c*i + max(0LL, (x-i))*a + max(0LL, (y-i))*b);
	}
	cout << ans << endl;
	return 0;
}