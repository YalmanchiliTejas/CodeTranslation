#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for(ll (i) = (0);(i) < (n);++i)
#define ALL(v) v.begin(),v.end()
#define LLINF 1000000000000000000LL
typedef long long ll;

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);

	int n;cin >> n;
	int ans = 0;
	vector<ll> v(n + 10, LLINF);

	REP(i, n){
		ll now;cin >> now;
		auto it = upper_bound(ALL(v), -now);
		if(*it == LLINF){
			ans++;
		}
		*it = -now;
	}

	cout << ans << endl;
	return 0;
}
