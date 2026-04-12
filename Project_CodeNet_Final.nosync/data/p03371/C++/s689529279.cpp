#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

lli a, b, c;
lli x, y;

int main(void){
	cin >> a >> b >> c >> x >> y;
	c = 2*c;
	lli ans = INT_MAX;
	rep(i, 1e5+5){
		ans = min(ans, c*i+a*max(0LL, x-i)+b*max(0LL, y-i));
	}
	cout << ans << endl;
	return 0;
}
