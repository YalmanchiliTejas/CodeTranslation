#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#define ll long long
#define LINF 0x3f3f3f3f3f3f3f3f
#define INF 0x3f3f3f3f
using namespace std;
const int MAX = 2e5 + 10;
const int MOD = 1e9 + 7;
int N, M, K, Q;
pair<int, int> boxes[MAX];
vector<pair<int, int>> vt;
int check[MAX];
int visited[MAX];
int n;

void add(int idx) {
	if (++check[idx] == 1) ++n;
}

int main()
{
	int i, j, k;
	scanf("%d", &N);
	for (i = 0; i < N; ++i) {
		scanf("%d%d", &boxes[i].first, &boxes[i].second);
		vt.push_back({ boxes[i].first, i });
		vt.push_back({ boxes[i].second, i });
	}
	sort(vt.begin(), vt.end());

	n = 0;
	memset(check, 0, sizeof(check));

	int f, l;
	int sz = vt.size();
	for (i = sz - 1; i >= 0; --i) {
		int idx = vt[i].second;
		if (!visited[idx]) visited[idx] = i;
	}

	for (i = 0; i < sz; ++i) {
		add(vt[i].second);
		if (n == N) {
			f = i;
			break;
		}
	}
	n = 0;
	memset(check, 0, sizeof(check));
	for (i = sz - 1; i >= 0; --i) {
		add(vt[i].second);
		if (n == N) {
			l = i;
			break;
		}
	}

	ll ans = (ll)(vt[sz - 1].first - vt[l].first)*(vt[f].first - vt[0].first);
	
	f = max(f, visited[vt[0].second]);
	for (i = 1; i <= l; ++i) {
		if (f == sz - 1) break;
		ans = min(ans, (ll)(vt[sz - 1].first - vt[0].first)*(vt[f].first - vt[i].first));
		f = max(f, visited[vt[i].second]);
	}
	printf("%lld", ans);
}