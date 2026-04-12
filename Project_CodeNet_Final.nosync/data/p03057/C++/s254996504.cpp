#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define all(v) (v).begin(),(v).end()
#define trav(x,v) for(auto &x : v)
#define sz(v) int(v.size())
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;

const ll md = 1e9+7;

vector<ll> calc(int n, int k){
	vector<ll> todo(n);
	todo[0] = -1;
	if(n > 1) todo[1] = 1;
	rep(i,0,n){
		if(i+1 < n) todo[i+1] = (todo[i+1] + 2*todo[i]) % md;
		if(i + k+1 < n) todo[i+k+1] = (todo[i+k+1] - todo[i]) % md;
		todo[i] *= -1;
	}
	return todo;
}

vector<ll> calc1(int n){
	vector<ll> todo(n);
	todo[0] = -1;
	if(n > 1) todo[1] = 1;
	vector<ll> ans(n);
	rep(i,0,n){
		if(i+1 < n) todo[i+1] = (todo[i+1] + todo[i]) % md;
		if(i+2 < n) todo[i+2] = (todo[i+2] + todo[i]) % md;
		todo[i] *= -1;
	}
	return todo;
}

ll solve(){
	int n, m;
	string s;
	cin >> n >> m >> s;
	if(s[0]=='B') trav(c, s) c = 'B'+'R'-c;
	if(count(all(s), 'R') == m){
		ll ans = 1;
		auto dp = calc1(n-1);
		for(int l = 1; l < n; ++l)
			ans += (l+1) * dp[n-l-1] % md;
		return ans;
	} else {
		if(n%2) return 0;
		int mx = n-1;
		rep(i,0,m) if(s[i]=='B' && s[i-1]=='R'){
			int j = i;
			while(j && s[j-1] =='R') --j;
			if(j == 0) mx = min(mx, i + (i%2==0));
			else if((i-j)%2) mx = min(mx, i-j);
		}
		auto dp = calc(n/2, (mx+1)/2);
		ll ans = 0;
		for(int l = 1; l <= mx; l += 2)
			ans += (l+1) * dp[(n-l-1)/2] % md;
		return ans;
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	ll res = solve();
	res %= md;
	if(res < 0) res += md;
	cout << res << endl;
}