#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pii pair<ll, ll>
#define to second
#define cost first
typedef long long ll;
typedef long double ld;
using namespace std;

ll num[3005];
ll dp[3005][3005];

ll answer(int i, int j, int turn) {
	if(dp[i][j] != -1) return dp[i][j];
	if(i == j) return turn? num[i] : 0;

	if(turn) return dp[i][j] = max(num[i]+answer(i+1, j, turn^1), num[j]+answer(i, j-1, turn^1));
	else return dp[i][j] = min(answer(i, j-1, turn^1), answer(i+1, j, turn^1));
}

int main()
{	
	ll n, i;
	ll sum = 0;

	cin >> n;
	for(i = 0; i < n; i++) cin >> num[i], sum += num[i];
	memset(dp, -1, sizeof dp);
	cout << 2LL * answer(0, n-1, 1) - sum << endl;

    return 0;
}