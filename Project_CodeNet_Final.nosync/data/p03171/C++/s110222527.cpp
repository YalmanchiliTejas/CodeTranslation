#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
#define MXN 3003
ll a[MXN], dp[MXN][MXN];
bool mark[MXN][MXN];

ll calc(int l, int r, bool turn)
{
	if(l==r) return turn? a[l]:-a[l];
	if(mark[l][r]) return dp[l][r];

	if(turn) dp[l][r] = max(calc(l+1, r, !turn)+a[l], calc(l, r-1, !turn)+a[r]);
	else dp[l][r] = min(calc(l+1, r, !turn)-a[l], calc(l, r-1, !turn)-a[r]);
	mark[l][r] = true;
	return dp[l][r];
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin>>N;
	for(int i=1; i<=N; i++) cin>>a[i];

	cout << calc(1, N, true) << '\n';
	return 0;
}