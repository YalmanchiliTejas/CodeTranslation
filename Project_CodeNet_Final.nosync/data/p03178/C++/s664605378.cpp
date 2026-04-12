#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
const int md = 1e9+7;
int d, sz, ac;
long long dp[105];
string s;
int main(){
	cin >> s >> d;
	rep(i,s.size()){
		long long tmp[105] = {};
		rep(j,d) rep(k,10) (tmp[(j+k)%d] += dp[j]) %= md;
		rep(j,s[i]-'0') (tmp[(ac+j)%d] += 1) %= md;
		rep(j,d) dp[j] = tmp[j];
		ac += s[i]-'0';
	}
	printf("%lld\n", (dp[0] + (ac%d == 0) - 1 + md) % md);
}