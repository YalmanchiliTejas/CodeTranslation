#include <bits/stdc++.h>
using namespace std;


int main() {
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;
	int ans;
	if(A + B > 2 * C){
		if(X > Y){
			ans = Y * 2 * C + min((X - Y) * A, (X - Y) * 2 * C);
		}
		else{
			ans = X * 2 * C + min((Y - X) * B, (Y - X) * 2 * C);
		}
	}
	else{
		ans = A * X + B * Y;
	}
	cout << ans << endl;
	return 0;
}