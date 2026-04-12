#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define P pair<int,int>
#define PI 3.141592653589793
const int INF = 1001001001;
const ll MX = 1e18;
const int mod = 1000000007;
template<class T> inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];

	ll sum = 0, ans = 0;
	rep(i, n) {
		sum += a[i];
		sum %= mod;
	}
	
	rep(i, n-1) {
		sum -= a[i];
		if (sum < 0) sum += mod;
		ans += sum * a[i];
		ans %= mod;
	}
	cout << ans << endl;
}