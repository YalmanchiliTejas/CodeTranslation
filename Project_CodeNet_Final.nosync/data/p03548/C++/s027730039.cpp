#include <iostream>
using namespace std;

int main() {
	int a, b, c,sum,ans;
	cin >> a >> b >> c;
	sum = b + c;
	
	a%sum >= c ? (ans = a / sum) : (ans = a / sum - 1);
	cout << ans << endl;

	return 0;
}