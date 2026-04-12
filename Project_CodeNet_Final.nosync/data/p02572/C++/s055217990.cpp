#include<iostream>
#include<stdio.h>
#include<string>
#include<cmath>
#include<math.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<unordered_map>
#define rep(i,n) for(ll i = 0; i < (n); i++)
#define rep2(i,n) for(int i = (n - 1); i >= 0; i--)
#define PI 3.141592653589793

using namespace std;
using ll = long long;

int to[200000];
const int si[] = { -1,0,1,0 };
const int sj[] = { 0,-1,0,1 };

int main() {

	ll n;
	ll md = 1000000007;
	ll sum = 0;
	cin >> n;
	vector<int> a(n);
	rep(i, n) {
		cin >> a[i];
		sum += a[i];
		sum %= md;
	}
	ll ans = 0;
	rep(i, n) {
		sum -= a[i];
		if (sum < 0) sum += md;
		ans += (a[i] * sum);
		ans %= md;
	}
	cout << ans << endl;
	return 0;
}