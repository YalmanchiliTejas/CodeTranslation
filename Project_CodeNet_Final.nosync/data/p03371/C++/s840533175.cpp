#include <bits/stdc++.h>
using namespace std;


int main()
{


	int a, b, c, x, y, ans;
	cin >> a >> b >> c >> x >> y;



	ans = a * x + b * y;

	for (int i = 2;i <= 2 * max(x, y);i+=2) {
	
		int money;



		money = a * max(x - i / 2, 0) + b * max(y - i / 2, 0) + c * i;
		ans = min(ans, money);

	}

	cout << ans << endl;
}