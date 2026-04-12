#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define all(x) (x.begin(),x.end())
#define rep(i,a,b) for(int i=a;i<b;i++)
#define F first
#define S second
#define endl "\n"
#define FAST  ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define sz(a) (int)a.size()
#define deb(x) cout<<#x<<" "<<x<<endl;
#define Q(x) for(int i=0;i<x;i++)
#define show(x) for(auto i:x)cout<<i<<" ";cout<<endl;

using namespace std;
const ll mod = 1e9 + 7;

int main() {

	ll n;
	cin >> n;
	vll a(n);
	Q(n)cin >> a[i];
	vll ps(n);
	ps[0] = a[0];
	rep(i, 1, n) {
		ps[i] = (ps[i - 1] + a[i]) ;
	}
	ll ans = 0;
	rep(i, 0, n - 1) {
		ans += ((a[i] * ((ps[n - 1] - ps[i]) % mod))  % mod);
	}
	ans %= mod;
	cout << ans << endl;
	return 0;
}
