#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MAX_N=11000;
const int MOD=1e9+7;
string S;
int D;

ll dp[MAX_N][111];

ll dfs(int pos, int m, bool limit)
{
	if(pos==(int)S.length()) return m==0;
	if(!limit && dp[pos][m]!=-1) return dp[pos][m];
	ll res = 0;
	int ub = limit ? S[pos]-'0' : 9;
	for(int i=0;i<=ub; ++i){
		res = (res + dfs(pos+1, (m+i)%D, (limit && i==ub)))%MOD;
	}
	res %= MOD;
	if(!limit) dp[pos][m]=res;
	return res;
}

void solve()
{
    memset(dp, -1, sizeof(dp));
	int ans = dfs(0, 0, true) % MOD;
	cout << (ans-1+MOD)%MOD << endl;
}

int main()
{
	cin >> S >> D;
	solve();
	return 0;
}