//Classic
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define pi pair<int,int>
#define vp vector<pi>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define For(i,a,b) for(ll i=a;i<b;i++)
#define endl "\n"
#define debug(x) cout<<"AA Baju Smit------> "<<#x<<" -> "<<x<<endl
#define all(x) x.begin(),x.end()
#define mint map<int,int>
#define mod 1000000007
#define ciN cin
#define X INT_MAX
#define N INT_MIN
////////////////////////////////////////////////////////////////


void solve() {
	int n; ciN >> n;
	vi v(n); For(i, 0, n)cin >> v[i];
	ll here = v[0];
	ll ans = 0;
	for (int i = 1; i < n; i++) {
		ans += (1LL * here * v[i]) % mod;
		here += v[i];
		here %= mod;
	}
	cout << ans % mod << endl;
}




////////////////////////////////////////////////////////////////


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//int t; cin >> t;
	//while (t--)
	solve();


	return 0;
}





///////////////////////////////////////////////////////////////////////////////////////////
//Kai baju bhai???

