#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

int main(){
	ll a,b,c,x,y;
	cin >> a >> b >> c >> x >> y;
	ll ans = 0;
	if(x > y){
		ans = min({a*x+b*y, 2*c*x, 2*c*y + (x-y)*a});
	}else{
		ans = min({a*x+b*y, 2*c*y, 2*c*x + (y-x)*b});
	}
	cout << ans << endl;
	return 0;
}

