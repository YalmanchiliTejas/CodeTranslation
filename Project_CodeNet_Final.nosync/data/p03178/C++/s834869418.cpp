#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9+7;
const int MAX_N = 10006;
string K;
int N, D;
ll dp[MAX_N][102];

ll dfs(int at, int rem, bool zero, bool less)
{
	if(at == N){
		if(!rem) return 1;
		else return 0;
	}
	if(!zero && less){
		ll res = dp[at][rem];
		if(res != -1) return res;
	}
	ll res = 0;
	for(int i=0;i<=(less?9:K[at]-'0');++i){
		(res += dfs(at+1, (rem+i)%D, (zero&&!i), (less||(i<(K[at]-'0')))))%=MOD;
	}
	if(!zero && less) dp[at][rem]=res%MOD;
	return res;
}

void solve()
{
	N = K.length();
	memset(dp, -1, sizeof(dp));
	int ans = dfs(0,0,true,false);
	cout << (ans-1+MOD)%MOD << '\n';
}

int main()
{
	cin >> K >> D;
	solve();
	return 0;
}