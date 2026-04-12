#include <bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false);
#define rmod(x,y) ((((x)%y)+y)%y)
using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 1e5+5, maxd = 101;
const ll mod = 1e9+7;

string S;
int N, D;

ll dp[2][maxn][maxd][2];

ll solve(bool st, int n, int s, bool can){
	if (n == N) return st&&(s == 0);
	if (dp[st][n][s][can] != -1) return dp[st][n][s][can];
	ll ret = 0;
	//put zero
	ret += solve(st,n+1, s, can||(S[n]>'0'));
	if (!can){
		for(char i = '1'; i<S[n]; i++) //put smaller char
			(ret+= solve(1, n+1, (s+(i-'0'))%D, 1))%mod;
		if (S[n]>'0') ret+= solve(1, n+1, (s+(S[n]-'0'))%D, 0);
	}
	else{ //put whatever
		for(int i = 1; i<10; i++)
			(ret += solve(1, n+1,(s+i)%D, 1))%=mod;
	}
	return dp[st][n][s][can] = ret%mod;
}

int main(){
	memset(dp, -1, sizeof(dp));
	cin >> S >> D;
	N = S.size();
	cout << solve(0,0,0,0) << endl;
	return 0;
}
