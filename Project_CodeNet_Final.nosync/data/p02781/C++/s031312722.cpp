#pragma GCC optimize ("O3,unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define spIO ios::sync_with_stdio(false);cin.tie(0)
string n;
ll k;
ll dfs(int place,int total,bool open)
{
	if (total > k)
		return 0;
	if (place == n.size() - 1)
	{
		if (total < k - 1)
			return 0;
		else if (total == k)
			return 1;
		else
		{
			if (open)
				return 9;
			else
				return n[place] - '0';
		}
	}
	if (!open)
	{
		if (n[place] == '0')
			return dfs(place + 1, total, false);
		return dfs(place + 1, total, true) + (n[place] - '0' - 1) * dfs(place + 1, total + 1, true) + dfs(place + 1, total + 1, false);
	}
	return dfs(place + 1, total, true) + 9 * dfs(place + 1, total + 1, true);
}
void solve()
{
	cout << dfs(0,0,false);
}
int main()
{
	spIO;
	cin >> n >> k;
	
	solve();
	
}