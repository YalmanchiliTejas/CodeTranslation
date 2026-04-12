#include <iostream>
using namespace std;
typedef long long ll;
#define rep(i,s,n)for(ll i = s;i<n;i++)
#define repe(i,s,n)for(ll i = s;i<=n;i++)

/*template*/

int main() {
	ll A, B, C, X, Y; cin >> A >> B >> C >> X >> Y;

	//
	ll sum1 = X * A + Y * B;
	ll sum2 = 0;
	ll sum3 = 0;
	if (X >= Y) {
		sum2 = (X - Y)*A + Y * 2 * C;
		sum3 = X * 2 * C;
	}
	else {
		sum2 = (Y - X)*B + X * 2 * C;
		sum3 = Y * 2 * C;
	}
	ll min = sum1;
	if (min > sum2) min = sum2;
	if (min > sum3) min = sum3;
	cout << min << endl;

	return 0;
}