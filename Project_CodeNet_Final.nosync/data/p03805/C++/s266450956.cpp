#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue> 
#include <stack>
#include <set>
#include <list>

using namespace std;
typedef long long ll;
#define rep(i, s, e) for (int(i) = (s); (i) <= (e); ++(i))
#define all(x) x.begin(),x.end()

int n, m, ans = 0;
vector<vector<int>> g(10);
vector<bool> passed(10, false);

void dfs(int now, int cnt)
{
	if (passed[now])return;
	if (cnt == n)
	{
		++ans;
		return;
	}
	
	passed[now] = true;
	for (int next : g[now])
	{
		dfs(next, cnt + 1);
	}
	passed[now] = false;
	return;
}


int main()
{
	cin >> n >> m;
	rep(i, 0, m - 1)
	{
		int a, b; cin >> a >> b;
		--a, --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(0, 1);
	cout << ans << endl;
}
