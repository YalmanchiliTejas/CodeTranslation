#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;

ll level_all[100];
ll level_pat[100];

ll calc(ll level, ll under) {
	//cout << level << "," << under << "," << endl;
	if(level==0) {
		return (under>=1)?1:0;
	}
	ll all_layer = level_all[level];
	ll half_layer = (all_layer-1)/2;
	ll ans = 0;
	if(under>=half_layer) {
		ans += (level_pat[level]-1)/2;
		under -= half_layer;
		//cout << " " << under << "," << half_layer << endl;
		if(under>0) {
			ans++;
			under--;
		}
		if(under>0) {
			ans += calc(level-1,under);
		}
	}else {
		ans = calc(level-1,under-1);
	}
	//cout << level << "," << under << "," << ans << endl;
	return ans;
}

int main() {
	ll n,x;
	cin >> n >> x;
	level_all[0] = 1;
	level_pat[0] = 1;
	for(ll i = 1; i <= 50; i++) {
		level_all[i] = level_all[i-1]*2+3;
		level_pat[i] = level_pat[i-1]*2+1;
	}

	ll ans = calc(n,x);
	cout << ans << endl;
}
