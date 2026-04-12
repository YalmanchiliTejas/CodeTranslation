#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pa;
typedef unsigned int uint;
typedef unsigned long long ull;
int main() {
	ll n, x, m,ans=0,flag=-1,pan=1,t=0,tt=0,k=150000;
	cin >> n >> x >> m;
	ll xx = x;
	for (ll i = 0; i < n; i++) {
		int p = 1;
		ans += x;
		x = x * x;	
		if (k > 1)k--;
		if (pan==1 &&flag==-1&&k==1)pan = 0, flag = x % m,p=0;
		x %= m;
		if (p && !pan && x == flag) {
			ll ttt = ((n - 1 - i) / tt);
			ans += ttt * t;
			i += ttt * tt;
			pan = 2;
			}
			else if (!pan) { t += x, tt++; }
	}
	cout << ans << endl;
	return 0;
}