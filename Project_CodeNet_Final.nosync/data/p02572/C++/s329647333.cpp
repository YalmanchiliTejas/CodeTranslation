/*
	JAI JAGANNATH!
*/
//@Author : zanj0

#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;

#define ff              first
#define ss              second
#define pb              push_back
#define MOD             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define w(x)            lli x; cin>>x; while(x--)

void zanj0()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

}
lli add(lli a, lli b) {
	return ((a % MOD) + (b % MOD)) % MOD;
}
lli mul(lli a, lli b) {
	return ((a % MOD) * (b % MOD)) % MOD;
}
void solve() {
	lli n;
	cin >> n;
	vector <lli> v(n);
	for (lli i = 0; i < n; i++) {
		cin >> v[i];
	}
	lli ret = 0;
	lli sum = 0 ;
	for (lli i = n - 1; i >= 0; i--) {
		ret = add(ret, (mul(v[i], sum)));
		sum = add(sum, v[i]);
	}
	cout << ret << endl;
}
int main()
{
	zanj0();
	solve();
	return 0;
}