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
#include <stack>
#include <cmath>
#define ll long long
#define LINF 0x3f3f3f3f3f3f3f3f
#define INF 0x3f3f3f3f
using namespace std;
const int MAX = 1e5 + 10;
const ll MOD = 1e9 + 7;
int N, M, K, Q;
vector<pair<ll, int>> xpos, ypos;
int p[MAX];
int cnt[MAX];
bool flag;

int _find(int x) { return p[x] == x ? x : p[x] = _find(p[x]); }
void _union(int x, int y) {
	int tmp = cnt[_find(x)];
	cnt[_find(x)] += cnt[_find(y)];
	cnt[_find(y)] += tmp;
	if (cnt[_find(x)] == N || cnt[_find(y)] == N) flag = true;
	p[_find(y)] = _find(x);
}

int main()
{
	int i, j, k;
	scanf("%d", &N);
	ll x, y;
	for (i = 1; i <= N; ++i) {
		scanf("%lld%lld", &x, &y);
		xpos.push_back({ x, i });
		ypos.push_back({ y, i });
	}
	sort(xpos.begin(), xpos.end());
	sort(ypos.begin(), ypos.end());

	priority_queue<pair<ll, pair<int, int>>> pq;
	
	for (i = 0; i < xpos.size() - 1; ++i) {
		ll dif = xpos[i + 1].first - xpos[i].first;
		pq.push({ -dif, {xpos[i + 1].second, xpos[i].second} });
	}

	for (i = 0; i < ypos.size() - 1; ++i) {
		ll dif = ypos[i + 1].first - ypos[i].first;
		pq.push({ -dif, {ypos[i + 1].second, ypos[i].second} });
	}
	
	flag = false;
	for (i = 1; i <= N; ++i) {
		p[i] = i;
		cnt[i] = 1;
	}

	ll cost = 0;
	while (!flag) {
		pair<ll, pair<int, int>> tmp = pq.top();
		pq.pop();
		ll c = -tmp.first;
		int idx1 = tmp.second.first;
		int idx2 = tmp.second.second;
		if (_find(idx1) != _find(idx2)) {
			cost += c;
			_union(idx1, idx2);
		}
	}
	printf("%lld", cost);

	

}
