#include <cmath>
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<set>
#include<bitset>
#include<iomanip>
#include<stack>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
ll a[2000005];
int main(void) {
	int n;
	cin >> n;
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		sum -= a[i];
		
		ans += ((sum%inf) * (a[i]%inf));
		ans %= inf;
		
	}
	cout << ans << endl;
	return 0;
}