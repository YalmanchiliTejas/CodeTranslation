#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INFI = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 3e3+2;
int N;
ll a[MAXN], dp[MAXN][MAXN];
bool vis[MAXN][MAXN];
ll solve(int l, int r){
	if(vis[l][r])return dp[l][r];
	vis[l][r] = true;
	if(l==r)return dp[l][r] = a[l];
	return dp[l][r] = max(a[l]-solve(l+1, r), a[r]-solve(l, r-1));
}
int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> N;
	for(int i = 1;i<=N;i++)cin >> a[i];
	cout << solve(1, N) << nl;
}