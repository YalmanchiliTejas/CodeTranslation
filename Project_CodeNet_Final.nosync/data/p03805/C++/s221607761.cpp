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

using namespace std;
typedef long long ll;
#define rep(i, s, e) for (int(i) = (s); (i) <= (e); ++(i))
#define all(x) x.begin(),x.end()

int n, m, ans = 0;
vector<bool> passed;
vector<vector<int>> vec;

void dfs(int now, int cnt)
{
	if (passed[now])return;
	if (cnt == n)
	{
		++ans;
		return;
	}
	passed[now] = true;
	for (int x : vec[now])
	{
		dfs(x, cnt + 1);
	}
	passed[now] = false;
	return;
}

int main()
{
	cin >> n >> m;
	vec.resize(n + 1);
	rep(i, 1, m)
	{
		int a, b; cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	passed.resize(n + 1);
	dfs(1, 1);
	cout << ans << endl;
}