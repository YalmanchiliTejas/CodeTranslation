#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef pair<int,int> P;
typedef long long ll;
const int INF = 1001001001;
const ll INFL = 1e17;
const int MOD = 1e9+7;


int main(){
	ll n,x,m;
	cin >> n >> x >> m;
	vector<int> memo(m,0);
	int idx = 1;
	memo[x] = idx;
	vector<ll> ans_tot;
	ans_tot.push_back(0);
	ans_tot.push_back(x);
	ll loop_start;
	ll loop_end;
	bool isloop = false;
	while(idx < n){
		idx++;
		ll now = x*x % m;
		if(memo[now] != 0){
			loop_start = memo[now];
			loop_end = idx-1;
			isloop = true;
			break;
		}
		x = now;
		memo[now] = idx;
		ans_tot.push_back(ans_tot[idx-1]+now);
	}
	ll ans = 0;
	if(isloop){	
		ans += ans_tot[loop_start-1];
		ll loop_sum = ans_tot[loop_end] - ans_tot[loop_start-1];
		ll loop_length = loop_end - loop_start + 1;
		ll loop_count = (n-loop_start+1) / loop_length;
		ll res = (n-loop_start+1) % loop_length;
		ans += loop_sum * loop_count;
		ans += ans_tot[loop_start+res-1] - ans_tot[loop_start-1];
	}
	else ans = ans_tot.back();
	cout << ans << endl;
	return 0;
}