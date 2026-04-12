#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vint;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define be(v) (v).begin(), (v).end()
ll mod = 1000000007;

int main() {
	int n; cin >> n;
	ll s=0;
	vint a(n);
	rep(i,n) {
		cin >> a[i];
		s+=a[i];
	}
	ll ans=0;
	for(int i=0;i<n-1;i++) {
		s-=a[i];
		ans+=(s%mod)*a[i];
		ans%=mod;
	}
	cout << ans << endl;
}