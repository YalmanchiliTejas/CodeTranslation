#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define MOD ((int)(1e9) + 7)
#define fast cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)
#define filename "lynext"
#define freop freopen(filename ".cik","w",stdout);freopen(filename ".gir","r",stdin)
const long long int N = ((long long int)4e3) + 5;
const long long int M = ((long long int)1e3) + 5;
const long long int llinf = (long long int)1e18;
const int inf = INT_MAX;
typedef long long int lli;

lli n;
lli arr[N];
lli tot;
lli dp[N][N];

lli f (lli alinanLeft, lli alinanRight, bool taro, lli a)
{
	if (dp[alinanLeft][alinanRight] != -1)
		return dp[alinanLeft][alinanRight];
	if (a == n)
		return 0;
	if (taro)
	{
		return dp[alinanLeft][alinanRight] = max(f(alinanLeft, alinanRight + 1, false, a + 1) + arr[n - alinanRight - 1],f(alinanLeft + 1,alinanRight,false, a + 1) + arr[alinanLeft]);
	}
	else
	{
		return dp[alinanLeft][alinanRight] = min(f(alinanLeft, alinanRight + 1, true,a + 1),f(alinanLeft + 1,alinanRight,true,a + 1));
	}
	return -1;
}

int main ()
{
	fast;
	//freop;
	cin >> n;
	memset(dp, -1, sizeof dp);
	for (int i = 0; i < n; i++)
		cin >> arr[i],tot += arr[i];
	lli ans = f(0,0,true,0);
	//cout << "Taro : " << ans << "\n";
	//cout << "Jiro : " << tot - ans << "\n";
	cout << ans - (tot - ans) << "\n";
}
