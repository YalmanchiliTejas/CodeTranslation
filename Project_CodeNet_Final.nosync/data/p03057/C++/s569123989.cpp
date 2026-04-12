#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <cassert>
using namespace std;
typedef long long ll;
ll dp[200010] = {},fib[200010],mod = 1000000007;
string s;
vector<pair<char,int>> v;
int main(){
	ll i,j,n,m;
	cin >> n >> m >> s;
	if(s[0]=='B'){
		for(i=0;i<m;i++){
			if(s[i]=='R') s[i] = 'B';
			else s[i] = 'R';
		}
	}
	for(i=0;i<m;i++){
		if(i==0 || v.back().first!=s[i]){
			v.push_back({s[i],1});
		}else{
			v.back().second++;
		}
	}
	if(v.size()==1){
		fib[0] = 1,fib[1] = 1;
		for(i=2;i<=n;i++){
			fib[i] = (fib[i - 1] + fib[i - 2])%mod;
		}
		cout << (fib[n] + fib[n - 2])%mod << endl;
		return 0;
	}
	if(n&1){
		cout << 0 << endl;
		return 0;
	}
	if(v.back().first=='R'){
		v.pop_back();
	}
	int mn = -1;
	for(i=0;i<v.size();i++){
		if(i==0){
			mn = v[i].second + 1 - (v[i].second&1);
		}
		if(v[i].first=='R' && (v[i].second&1)){
			mn = min(mn,v[i].second);
		}
	}
	mn++;
	dp[0] = 1;
	ll sum = 1;
	for(i=2;i<=n;i+=2){
		(dp[i] += sum) %= mod;
		(sum += dp[i]) %= mod;
		if(i>=mn) sum -= dp[i - mn];
		if(sum<0) sum += mod;
	}
	ll ans = 0;
	for(i=2;i<=mn;i+=2){
		(ans += i*dp[n - i]) %= mod;
	}
	cout << ans << endl;
}