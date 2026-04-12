#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <tuple>
#include <utility>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
const int INF = 1000000000;
const long long INFL = 2e18;
const int MOD = 1000000007;
int main(){
	ll n,x,m;
	cin >> n >> x >> m;

	map<ll,ll> bef_pos;

	bef_pos[x] = 1;

	vector<ll> v;
	v.push_back(x);
	ll now = x;
	ll loop_len = 0;
	ll cnt = 1;
	while(true){
		cnt++;
		ll next = now * now % m;
		if(bef_pos[next] != 0){
			loop_len = cnt - bef_pos[next];
			break;
		}
		v.push_back(next);
		bef_pos[next] = cnt;
		now = next;
	}

	//cout << loop_len << endl;
	//for(ll i = 0;i < v.size();i++)cout << v[i] << endl;

	ll rem_len = v.size() - loop_len;

	if(n <= rem_len){
		ll ans = 0;
		for(ll i = 0;i < rem_len;i++){
			ans += v[i];
		}
		cout << ans << endl;
	}
	else{
		ll rem = 0;
		for(ll i = 0;i < rem_len;i++){
			rem += v[i];
		}

		vector<ll> lp_val(loop_len,0);
		lp_val[0] = v[v.size()-loop_len];
		ll idx = 0;
		for(ll i = v.size() - loop_len + 1;i < v.size();i++){
			idx++;
			lp_val[idx] = lp_val[idx-1] + v[i];
		}

		//for(ll i = 0;i < loop_len;i++)cout << lp_val[i] << endl;
		ll ans = rem + (n - rem_len) / loop_len * lp_val[loop_len-1];

		//cout << ans << endl;

		if((n - rem_len) % loop_len != 0){
			ans += lp_val[(n-rem_len) % loop_len - 1];
		}

		cout << ans << endl;
	}
}
