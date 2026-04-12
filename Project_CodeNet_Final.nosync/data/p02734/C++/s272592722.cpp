#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll n,s,m=998244353,ans=0;
	cin >> n >> s;
	vector<ll> a(n),dp(3001,0);
	for(auto &&x:a)cin >> x;
	for(auto &&x:a){
		vector<ll> t(3001,0);
		for(int i=0;i<3001;i++){
			( t[i] += dp[i] ) %= m;
			if(i+x<=3000)( t[i+x] += dp[i] ) %= m;
		}
		t[0]++;
		t[x]++;
		dp = t;
		( ans += dp[s] ) %= m;
	}
	cout << ans << endl;
}