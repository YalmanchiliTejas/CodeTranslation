#include<iostream>
#include<string>
#include<math.h>
#include<vector>
#include<algorithm>

#define ll long long
#define vl vector<ll>
#define vvl vector< vector<ll> >
using namespace std;

int main(){
	ll n; cin >> n;
	ll now_max = 0;
	ll ans = 0;
	for (int i = 0; i < n; ++i){
		ll h; cin >> h;
		if (h >= now_max){
			ans++;
			now_max = h;
		}
	}cout << ans << endl;
	return 0;
}