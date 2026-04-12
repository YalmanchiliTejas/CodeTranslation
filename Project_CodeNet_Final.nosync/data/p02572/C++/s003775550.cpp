#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#define PI 3.14159265359
typedef long long ll;
const int MOD = 1e9+7;
const ll LLINF = 7e18;
using namespace std;


int main(){
	int n;
	cin >> n;
	vector<ll> a(n+1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	vector<ll> sum(n+1);
	sum[0] = 0;
	for (int i = 1; i <= n; i++){
		sum[i] = sum[i-1] + a[i];
		sum[i] %= MOD;
	}
	ll ans = 0;
	for (int i = n; i >= 1; i--){
		ans += a[i]*sum[i-1];
		ans %= MOD;
	}
	cout << ans << endl;
	return 0;
}