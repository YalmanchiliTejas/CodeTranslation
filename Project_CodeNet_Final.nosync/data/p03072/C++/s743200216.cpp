//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 0x6fffffff
#define INFL 0x6fffffffffffffffLL

int main() {
	ll		a,b,c,i,j,k,l,m,n,x,y;
	ll		ans = 0;
	string	s;
	cin >> n;
	vector<ll>	h(n);
	for(i=0;i<n;i++) cin >> h[i];
	x = h[0];
	ans = 1;
	for(i=1;i<n;i++) {
		if (x <= h[i]) {
			ans ++;
			x = h[i];
		}
	}
	cout << ans << endl;
	return 0;
}
