/*
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#pragma GCC optimize("Os")
#pragma GCC target("avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("Os")
*/
#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld; 

#define X first
#define Y second
#define MP make_pair

using namespace std;
    
const int N = 3e3 + 123;
const ll mod = 1e9 + 7;
const ll INF = 1e18;

ll dp[2][N][N], was[2][N][N], a[N];
ll rec(int v, int l, int r){
	if(l > r)
		return 0;
	if(was[v][l][r])
		return dp[v][l][r];
	was[v][l][r] = 1;
	if(v == 0){
		dp[v][l][r] = max(rec(1 - v, l + 1, r) + a[l], rec(1 - v, l, r - 1) + a[r]);
	}
	else{
	    dp[v][l][r] = min(rec(1 - v, l + 1, r) - a[l], rec(1 - v, l, r - 1) - a[r]);
	}
	return dp[v][l][r];
}

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	cout << rec(0, 1, n);
	return 0;
}