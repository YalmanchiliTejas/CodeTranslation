#include <bits/stdc++.h>

#pragma region Macro
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define SORT(v) sort(v.begin(), v.end())
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
#define vi vector<int>
#define vvi vector<vector<int>>
#define chmax(x,y) (x = max(x,y))
#define chmin(x,y) (x = min(x,y))

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#pragma endregion

void solve(){
	#define int ll
	// ここに処理を記述
	// コンパイル時はエイリアス「gpp」--> c++17でコンパイル
	int n,x,m;
	cin >> n >> x >> m;

	map<int,int> mp;
	vi a;
	int cnt = 0;
	ll tot = 0;
	while(mp.count(x) == 0){
		a.pb(x);
		tot += x;
		mp[x] = cnt;
		++cnt;
		x = x*x%m;
	}
	if(n <= cnt){
		ll ans = 0;
		rep(i,n) ans += a[i];
		cout << ans << endl;
		return;
	}
	ll lp_sum = 0;
	int s = cnt - mp[x];
	FOR(i,mp[x],cnt) lp_sum += a[i];
	ll ans = tot;
	n -= cnt;
	ans += n/s*lp_sum;
	n %= s;
	int itr = mp[x];
	rep(i,n) ans += a[itr + i];
	cout << ans << endl;
	return;

}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(15);
	
	solve();
	return 0;
}