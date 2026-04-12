#include<iostream>
#include <algorithm>

using namespace std; 

int A, B, C, X, Y;

int main(void) {

	cin >> A >> B >> C >> X >> Y;

	long long int ans = (long long int)5000 * 10000000;

	

	//========
	ans = min(ans,(long long int) A*X + B*Y);

	//===========

	long long int tmp;
	tmp = C * 2 * X; if (Y > X) { tmp += (Y - X)*B; }

	ans = min(ans, tmp);

	//===========
	tmp = C * 2 * Y; if (X > Y) { tmp += (X - Y)*A; }
	ans = min(ans, tmp);


	cout << ans << endl;

	//system("pause");
	return 0;
}