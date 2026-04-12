#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll INF = 1LL << 60;
const int maxn = 2*1e5+10;

int n;
ll a[maxn];
map<pair<int,int>,ll> dp;

ll get_ans(int pos,int picked){
	if(picked > n/2 || picked + (n-pos+1)/2 < n/2) return -INF;
	if(pos >= n) return 0;
	pair<int,int> cur = {pos,picked};
	if(dp.count(cur)) return dp[cur];
	return dp[cur] = max(get_ans(pos+1,picked),get_ans(pos+2,picked+1)+a[pos]);
}

void solve(){
	cin >> n;
	for(int i=0;i<n;++i) cin >> a[i];
	cout << get_ans(0,0) << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	//cin >> t;
	while(t--){ 
		solve();
	}
	return 0;
}