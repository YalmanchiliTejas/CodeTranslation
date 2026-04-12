#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <deque>
#include <string>
#include <iostream>
#include <climits>
using namespace std;

#define int long long
const int INF = LLONG_MAX*0.8;
typedef pair<int, int> PII;

int N;
vector<PII> v;

signed main()
{
	int mi = INF, ma = -INF;
	int rMax = -INF, bMin = INF;
	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i].first >> v[i].second;
		if (v[i].first > v[i].second) swap(v[i].first, v[i].second);
		mi = min(mi, v[i].first);
		ma = max(ma, v[i].second);
		rMax = max(rMax, v[i].first);
		bMin = min(bMin, v[i].second);
	}
	int ans = (rMax - mi)*(ma - bMin);

	int rMin = INF;
	sort(v.begin(), v.end());
	for (int i = 0; i < N - 1; i++)
	{
		rMax = max(rMax, v[i].second);
		rMin = min(rMin, v[i].second);
		ans = min(ans, (rMax - min(rMin, v[i + 1].first))*(ma - mi));
	}
	printf("%lld\n", ans);
	return 0;
}