#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<string>
#include<limits.h>
#include<utility>
#include<vector>
#include<tuple>
#include <map>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i,n) for(ll i=0;i<n;i++)
#define ALL(A) A.begin(),A.end()


int main() {
	ll n;
	cin >> n;
	ll mod = 1e9 + 7;
	vector<ll> a(n);
	ll sum = 0;
	rep(i, n) {
		cin >> a[i];
		sum += a[i];
		sum = sum % mod;
	//	cout << sum << endl;
	}
	ll ans = 0;
	rep(i, n - 1) {
		sum -= a[i];
		sum = (sum + mod) % mod;
		ans += sum * a[i];
		ans = ans % mod;
		ans = (ans + mod) % mod;
	}

	cout << ans << endl;
}
