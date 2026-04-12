#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define f first
#define s second
#define pb push_back
#define mk make_pair
#define MOD 1000000007
#define fo(i,a,b) for(i=a;i<b;i++)
#define foe(i,a,b) for(i=a;i<=b;i++)
#define boost ios::sync_with_stdio(false); cin.tie(0)
using namespace std;
const int MAX = 3005;
const ll inf = 1e16;
int arr[MAX], n;
ll memo[MAX][MAX];
ll func(ll x, ll y, int p)
{
	return (p > 0 ? max(x, y) : min(x, y));
}
ll solve(int bg, int en)
{
	if(bg > en)
	return 0;
	
	if(memo[bg][en] != inf)
	return memo[bg][en];
	
	int p = ((n - (en - bg)) % 2 ? 1 : -1);
	return memo[bg][en] = func(solve(bg, en - 1) + p * arr[en], solve(bg + 1, en) + p * arr[bg], p);
}
int main()
{
	boost;
	int i, j;
	cin >> n;
	fo(i, 0, n)
	cin >> arr[i];
	fo(i, 0, MAX)
	{
		fo(j, 0, MAX)
		memo[i][j] = inf;
	}
	cout << solve(0, n - 1) << '\n';
}