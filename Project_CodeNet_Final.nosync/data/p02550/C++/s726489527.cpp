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
const LLONG MOD = 998244353;

LLONG dp[200001];

int main()
{
	// ループするまで続ける
	LLONG N, X, M; cin >> N >> X >> M;
	vector<LLONG> as;
	set<LLONG> aSet;
	LLONG ans = 0;
	LLONG prev = X;
	for (LLONG i = 0; i < N; ++i)
	{
		as.push_back(prev);
		aSet.insert(prev);
		ans += prev;
		LLONG next = (prev * prev) % M;
		if (next == prev)
		{
			ans += next * (N - i - 1);
			break;
		}
		else if (aSet.count(next))
		{
			int pos = distance(as.begin(), find(as.begin(), as.end(), next));
			ans = accumulate(as.begin(), as.end(), 0LL);
			LLONG cycleSize = as.size() - pos;
			LLONG cycleSum = accumulate(as.begin() + pos, as.end(), 0LL);
			LLONG remNum = N - as.size();
			ans += cycleSum * (remNum / cycleSize);
			remNum %= cycleSize;
			ans += accumulate(as.begin() + pos, as.begin() + pos + remNum, 0LL);
			break;
		}
		prev = next;
	}
	cout << ans << endl;
}
