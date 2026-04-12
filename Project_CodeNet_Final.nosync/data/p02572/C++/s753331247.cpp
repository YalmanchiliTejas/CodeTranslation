#include <algorithm>
#include <cmath>
#include <vector>
#include <functional>
#include <cstdlib>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <ctype.h>
#include <climits>
#include <queue>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < (ll)(n); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}

int main(){
	int n;
	const ll mod = 1000000007;
	cin >> n;
	vector<ll> a(n),s(n+1);
	s[0]=0;
	REP(i,n){
		cin >> a[i];
		s[i+1] = s[i] + a[i];
		s[i+1] %= mod;
	}

	ll ans = 0;
	
	for(int i=n-1;i>=0; i--){
		ll tmp = a[i]*s[i];
		ans += tmp%mod;
		ans %= mod;
	}
	
	cout << ans << endl;
	
	return 0;
}