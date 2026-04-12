#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;
const ll MAX = 100100;
const double PI = 3.1415926;

#define vll vector<ll>
#define max_heap priority_queue<int>
#define min_heap priority_queue<int , vector<int>, greater<int> >
#define pb push_back
#define all(container) container.begin(), container.end()
#define pll pair<ll,ll>
#define printArr(name,from,to) for(int x = from; x < to; x++) cout << name[x] << " ";
// #define traverse( container, it) for( typeof(container.begin()) it = container.begin(); it!=container.end(); it++)
string k;
int d,n;
ll dp[110][10100][2];

int get(int i)
{
	return (((int)k[i]) - 48);
}
ll f(ll sum, ll index, bool eq)
{
	if (index == n)
	{
		if (sum % d == 0)
			return 1;
		else
			return 0;
	}
	if (dp[sum][index][eq] != -1)
		return dp[sum][index][eq];

	ll ans = 0;
	if (eq)
	{
		int digit = get(index);
		for(int i = 0; i < digit; ++i)
		{
			ans += (f((sum + i)%d, index + 1, !eq)%MOD);
			ans %= MOD;
		}
		ans += (f((sum + digit)%d, index + 1, eq)%MOD);
		ans %= MOD;
	}
	else
	{
		for(int i = 0 ; i <= 9; ++i)
		{
			ans += (f((sum + i)%d, index + 1, eq)%MOD);
			ans %= MOD;
		}
	}
	return (dp[sum][index][eq] = ans);
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	memset(dp,-1,sizeof(dp));
	cin >> k;
	cin >> d;
	n = k.length();
	ll answer = f(0,0,1);
	answer--;
	if (answer == -1)
		answer = MOD - 1;

	cout << answer << endl;
	return 0;
}
