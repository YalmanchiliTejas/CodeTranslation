#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define foru(i,a,n) for(ll i=(a); i<=(n); ++i)
#define ford(i,n,a) for(ll i=(n); i>=(a); --i)
using namespace std;
const int inf = 1e9;
const int N = 3030;
ll n, a[N], dp[N][N][2], vis[N][N][2];

ll sol(int L, int R, int player){
	if(L==R){
		if(player == 1) return a[L]; else return -a[L];
	}
	if(vis[L][R][player]) return dp[L][R][player];

	vis[L][R][player] = 1;
	ll opt1 = sol(L+1, R, player^1);
	ll opt2 = sol(L, R-1, player^1);
	if(player)
		return dp[L][R][player] = max(a[L] + opt1, a[R] + opt2);
	else
		return dp[L][R][player] = min(-a[L] + opt1, -a[R] + opt2);
}

int main() {
	//freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin >>n;
	foru(i,1,n) cin >>a[i];

	memset(vis, 0, sizeof(vis));

	//sol(1,n,0) bat dau tu player 1 chon la bai tu a[1]..a[n]
	cout <<sol(1, n, 1);
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << " ms\n";
	return 0;
}