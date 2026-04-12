#include <bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false);
using namespace std;
typedef long long ll;
typedef long double ld;


string s;
int N, K;
int dp[2][101][4][2];
ll solve(bool started, int n, int nz, bool smaller){
	if (n == N) return (nz == K)&&started; 
	if (dp[started][n][nz][smaller] != -1)
		return dp[started][n][nz][smaller];
	ll ret = 0;
	if (nz == K)
		ret+= solve(1, n+1, nz, smaller||(s[n]>'0')); //can only put 0
	else if (nz<K){
		ret += solve(started, n+1, nz, smaller||(s[n]>'0')); //put 0
		if (smaller) for(char h = '1'; h<='9'; h++) ret+= solve(1, n+1, nz+1, 1);			
		else {
			for(char h = '1'; h<s[n]; h++)
				ret+= solve(1, n+1, nz+1, 1); //smaller number here, can put w/e on next
			if (s[n]>'0') ret+= solve(1, n+1, nz+1, 0); //put same number
		}
	}
	return dp[started][n][nz][smaller] = ret;
}

int main(){
	cin >> s >> K;
	N = s.size();
	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0, 0, 0) << endl;
	return 0;
}
