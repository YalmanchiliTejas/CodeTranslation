#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 3005;
int N;
ll a[MAX_N];
ll dp[MAX_N][MAX_N];

ll go(int le, int ri)
{
	if(le > ri) return 0;
	if(le == ri) return a[le];
	ll& res = dp[le][ri];
	if(res != -1) return res;
	res = max(a[le]+min(go(le+2,ri),go(le+1,ri-1)),
			  a[ri]+min(go(le+1,ri-1),go(le,ri-2)));
	return res;
}

void solve()
{
	memset(dp, -1, sizeof(dp));
	ll ans = go(0, N-1);
	cout << 2*ans-accumulate(a,a+N,0LL) << '\n';
}

int main()
{
	cin >> N;
	for(int i=0;i<N;++i) cin >> a[i];
	solve();
	return 0;
}