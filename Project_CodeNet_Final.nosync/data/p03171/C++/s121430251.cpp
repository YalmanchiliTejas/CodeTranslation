#include <bits/stdc++.h>
#define ll long long
#define foru(i,a,n) for(int i=(a); i<=(n); ++i)
#define ford(i,n,a) for(int i=(n); i>=(a); --i)
using namespace std;
const ll inf = 1e15;
const int N = 3030;
ll n, a[N], s[N], dp[N][N];

ll sol(int L, int R){
	if(L == R) return a[L];
	if(dp[L][R] != inf) return dp[L][R];
	return dp[L][R] = max(a[L] - sol(L+1,R), a[R] - sol(L,R-1));
}

int main() {
	//freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin >>n;
	foru(i,1,n) cin >>a[i];
	
	foru(i,0,N-1) foru(j,0,N-1) dp[i][j] = inf;
	cout <<sol(1,n) <<"\n";
	
	//cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << " ms\n";
	return 0;
}