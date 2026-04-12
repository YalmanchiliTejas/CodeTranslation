#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <math.h>
#include <climits>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <map> 
#include <set>
#include <string>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> P;
const ll MD = 1000000007;

/* sample input

*/

int main()
{
	ll n;
	ll *x, *y;
	cin >> n;
	x = new ll[n];
	y = new ll[n];
	
	for (ll i = 0; i < n; i++) {
		cin >> x[i];
		y[i] = x[i];
	}
	sort(y, y + n);

	for (ll i = 0; i < n; i++) {
		ll pos = n / 2-1;
		if (x[i] <= y[pos]) {
			cout << y[pos+1] << endl;
		}
		else {
			cout << y[pos] << endl;
		}
	}

	return 0;
}