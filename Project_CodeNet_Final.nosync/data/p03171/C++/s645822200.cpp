#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define foru(i,a,n) for(ll i=(a); i<=(n); ++i)
#define ford(i,n,a) for(ll i=(n); i>=(a); --i)
using namespace std;
const int inf = 1e9;
const int N = 3030;
ll n, a[N], dp[N][N], vis[N][N];

ll sol(int L, int R){
	if(L==R) return a[L];
	if(vis[L][R]) return dp[L][R];
	vis[L][R] = 1;
	ll chontrai = a[L] - sol(L+1, R);
	ll chonphai = a[R] - sol(L, R-1);
	return dp[L][R] = max(chonphai, chontrai);
}

int main() {
	//freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin >>n;
	foru(i,1,n) cin >>a[i];

	memset(vis, 0, sizeof(vis));
	//sol(1,n,0) bat dau tu player 1 chon la bai tu a[1]..a[n]
	cout <<sol(1, n);
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << " ms\n";
	return 0;
}