#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<bitset>
#include<queue>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) FOR(i,0,n)
typedef long long ll;
int main(){
	ll n,k;
	cin >> n>>k;
	ll ans = 0;
	if (k==0) ans = n*n;
	else {
		FOR(i,k+1,n+1){
		//	if ((n-k)%i==0){
		//		ans += ((n-k)/i)*(i-k);
		//	}
		//	else {
				ll sub = (n-k)/i + 1;
				ans += sub*(i-k);
				ll subb = sub*i-n-1;
				if (subb>0) ans -= subb;
		//	}
		//	cout << ans << " " << subb << endl;
		}
	}

	cout << ans << endl;
	return 0;
}
