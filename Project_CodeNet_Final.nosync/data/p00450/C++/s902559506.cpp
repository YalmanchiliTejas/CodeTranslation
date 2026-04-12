#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <string>
#include <cstdio>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cstring>
#include <tuple>
#include <utility>
#include <list>
#include <cmath>

using namespace std;

typedef long long LL;
typedef vector<int> Array;
typedef pair<int, int> P;

const LL LINF = 1LL << 60;
const LL MOD = 100000;
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define all(c) (c).begin(), (c).end()

struct edge{ LL to, cost; edge(int t, LL c) :to(t), cost(c){} };

int dxk[] = { 1, 1, 1, 0, -1, 0 };
int dxg[] = { 0, 1, 0, -1, -1, -1 };
int dy[] = { -1, 0, 1, 1, 0, -1 };

int main()
{
	int n;
	while (cin >> n && n)
	{
		vector<P> arr;
		int fn; cin >> fn;
		arr.emplace_back(fn, 1);
		rep(i, n - 1)
		{
			int x; cin >> x;
			if (i % 2 == 1)
			{
				if (arr[arr.size() - 1].first == x) arr[arr.size() - 1].second++;
				else arr.emplace_back(x, 1);
			}
			else
			{
				if (arr[arr.size() - 1].first == x) arr[arr.size() - 1].second++;
				else
				{
					if (arr.size() == 1) arr[0] = P(x, arr[0].second + 1);
					else
					{
						arr[arr.size() - 2].second += arr[arr.size() - 1].second + 1;
						arr.pop_back();
					}
				}
			}
		}
		int ans = 0;
		for (auto x : arr) if (x.first == 0) ans += x.second;
		cout << ans << endl;
	}
	return 0;
}