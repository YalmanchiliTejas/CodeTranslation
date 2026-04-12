#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n;
	cin >> n;
	vector<ll> a(n);
	rep(i,n) cin >> a[i];
	ll ans = 0;
	while(true){
		sort(a.rbegin(), a.rend());
		if(a[0] < n) break;
		ll sub = a[0] / n;
		a[0] -= sub * n;
		for(int i = 1; i < n; ++i) a[i] += sub;
		ans += sub;
	}
	cout << ans << endl;
	return 0;
}
