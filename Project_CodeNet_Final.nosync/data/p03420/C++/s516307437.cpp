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
	ll n, k;
	cin >> n >> k;
	ll answer = 0;

	for (ll b = k + 1; b <= n; b++) {
		
		//for (ll a = k; a <= k + b -1;a++)
		//{
		//	if (a%b >= k) {
		//		ll num;
		//		num = (n - a) / b + 1;
		//		if (a == 0) {
		//			num--;
		//		}
		//		answer += num;
		//	}
		//}
		
		ll mod = n%b;
		ll add = (n + 1) / b*(b - k);
		if ((n+1)%b > k) {
			add += (n+1)%b- k;
		}
		if (k == 0) {
			add--;
		}
		
		answer += add;
	}
	cout << answer << endl;

	return 0;
}