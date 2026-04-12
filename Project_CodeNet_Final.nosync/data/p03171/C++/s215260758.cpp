//Inbornhandsome
#include <bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

#define endl '\n'
#define int long long

const int N = 3005;
int cache[N][N][2];
int n, a[N];

int solve(int i, int j, int cur) {
	if(i > j) 
		return 0;
	int &ans = cache[i][j][cur];
	if(ans != -1) 
		return ans;
	if(cur) ans = min(solve(i+1, j, cur^1) - a[i], solve(i, j-1, cur^1) - a[j]);
	else	ans = max(solve(i+1, j, cur^1) + a[i], solve(i, j-1, cur^1) + a[j]);
	return ans; 
}

int32_t main()
{
	IOS;

	cin >> n;
	for(auto &it : a) cin >> it;
	memset(cache, -1, sizeof cache);
	cout << solve(0, n-1, 0) << endl;

	return 0;
}