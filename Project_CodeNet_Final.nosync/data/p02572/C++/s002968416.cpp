//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 0x6fffffff
#define INFL 0x6fffffffffffffffLL

int main() {
	ll		b,c,h,i,j,k,l,m,n,x,y;
	ll		ans = 0;
	string	s;
	cin >> n;
	vector<ll>	a(n+1),t(n+1);
	for(i=0;i<n;i++) cin >> a[i];
	for(i=0;i<n;i++) t[i+1] = t[i] + a[i];
	//for(i=0;i<=n;i++) cout << a[i] << ' ' << t[i] << endl;
	for(i=0;i<n-1;i++) {
		ans += a[i]*((t[n] - t[i+1]) % 1000000007) % 1000000007;
		ans %= 1000000007;
		//cout << ans << endl;
	}

	cout << ans << endl;
	return 0;
}
