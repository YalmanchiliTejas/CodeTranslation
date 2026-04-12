#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define REP(i, n) for(int i = 0; i < n; ++i)
using namespace std;
using LLONG = long long;
const LLONG MOD = 1000000007;

int main()
{
	int H, W; cin >> H >> W;
	vector<char> as(H * W);
	REP(i, H * W) cin >> as[i];
	vector<int> path;
	int cur = 0;
	bool isPossible = true;
	// move with the shortest path
	for (;;)
	{
		path.push_back(cur);
		if (cur == H * W - 1)
		{
			break;
		}
		int row = cur / W;
		int col = cur % W;
		if (row < H - 1 && as[cur + W] == '#')
		{
			cur = cur + W;
		}
		else if (col < W - 1 && as[cur + 1] == '#')
		{
			cur = cur + 1;
		}
		// if cannot move, impossible
		else
		{
			isPossible = false;
			break;
		}
	}
	if (isPossible)
	{
		// if detour exists, impossible
		int pathLen = path.size();
		int moveNum = count(as.begin(), as.end(), '#');
		if (pathLen != moveNum)
		{
			isPossible = false;
		}
	}
	cout << (isPossible ? "Possible" : "Impossible") << endl;
}
