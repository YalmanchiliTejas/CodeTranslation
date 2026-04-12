#pragma region
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
//#define rep(i, s, e) for (int(i) = (s); (i) < (e); ++(i))
#define rep(i, e) for (int(i) = 0; (i) < (e); ++(i))
#define rrep(i, s) for (int(i) = (s) - 1; (i) >= 0; --(i))
#define all(x) x.begin(),x.end()
#pragma endregion


int main()
{
	int h, w; cin >> h >> w;
	vector<string> a(h); rep(i, h)cin >> a[i];
	//step数のチェック
	int cnt = 0;
	rep(i, h)rep(j, w)
	{
		if (a[i][j] == '#')++cnt;
	}
	if (cnt != h + w - 1)
	{
		cout << "Impossible" << endl;
		return 0;
	}
	//ルートの存在チェック
	vector<vector<bool>> v(h, vector<bool>(w, false));
	queue<pair<int, int>> q;
	if (a[0][0] == '#')q.push({ 0,0 });
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		int nx = x + 1;
		int ny = y;
		if (nx < h && ny < w && a[nx][ny] == '#')
		{
			v[nx][ny] = true;
			q.push({ nx,ny });
		}
		nx = x;
		ny = y + 1;
		if (nx < h && ny < w && a[nx][ny] == '#')
		{
			v[nx][ny] = true;
			q.push({ nx,ny });
		}
	}
	if (v[h - 1][w - 1])cout << "Possible" << endl;
	else cout << "Impossible" << endl;
}