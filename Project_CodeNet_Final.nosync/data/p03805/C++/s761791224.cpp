#include <iostream>
#include <iomanip>
#include <algorithm>
#include <bitset>
#include <string>
#include <cmath>
#include <complex>
#include <numeric>
#include <cassert>

#include <vector>
#include <array>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <utility>

#define int64 long long
#define uint64 unsigned long long
using namespace std;

int main()
{
	int64 nn, mm, aa, bb, ans = 0;
	cin >> nn >> mm;
	bool table[nn][nn];
	for(int64 ii = 0;ii < nn;ii++)
	{
		for(int64 jj = 0;jj < nn;jj++)
		{
			table[ii][jj] = false;
		}
	}
	for(int64 ii = 0;ii < mm;ii++)
	{
		cin >> aa >> bb;
		table[aa-1][bb-1] = true;
		table[bb-1][aa-1] = true;
	}
	queue<pair<int64, int64>> qq;
	qq.push(make_pair(0, 1));
	while(!qq.empty())
	{
		int64 here = qq.front().first;
		int64 memo = qq.front().second;
		qq.pop();
		if(memo == (1 << nn) - 1)
		{
			ans++;
		}
		else
		{
			for(int64 ii = 1;ii < nn;ii++)
			{
				if(table[ii][here] && !(memo & (1 << ii)))
				{
					qq.push(make_pair(ii, memo + (1 << ii)));
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
