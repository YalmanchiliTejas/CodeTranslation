#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 1, MOD = 1e9 + 7;

struct Point {
	int x, y, i;
	bool operator<(Point p) const {
		if (x == p.x) {
			return y < p.y;
		}
		return x < p.x;
	}
};

int mpA[N], mpB[N];
Point a[N], b[N];
int n;
set<pair<int, int>> segmentsX, segmentsY;
void doStuff(int index, set<pair<int, int>> &segments) {
	auto rit = segments.upper_bound({index, index});
	if (rit != segments.begin() && index == prev(rit)->second + 1) {
		auto p = *prev(rit);
		segments.erase(prev(rit));
		++p.second;
		segments.insert(p);
	} else if (rit != segments.end() && index == rit->first - 1) {
		auto p = *rit;
		segments.erase(rit);
		--p.first;
		segments.insert(p);
	} else {
		segments.insert({index, index});
	}
	rit = segments.upper_bound({index, index});
	if (rit != segments.begin() && rit != segments.end() && prev(rit)->second == rit->first) {
		auto p = *prev(rit);
		segments.erase(prev(rit));
		p.second = rit->second;
		segments.erase(rit);
		segments.insert(p);
	}
}

long long prim(int root) {
	bool vis[N] = {};
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; // cost 	node
	q.push({0, root});
	long long result = 0;
	while (q.size()) {
		pair<int, int> cur = q.top();
		q.pop();
		if (vis[cur.second]++)
			continue;
		result += cur.first;
		int indexA = mpA[cur.second], indexB = mpB[cur.second];
		
		doStuff(indexA, segmentsX);
		doStuff(indexB, segmentsY);
		
		auto it = prev(segmentsX.upper_bound({indexA, 1e9}));
		int leftA = it->first - 1, rightA = it->second + 1;
		if (0 <= leftA && leftA < n) {
			q.push({abs(a[indexA].x - a[leftA].x), a[leftA].i});
		}
		if (0 <= rightA && rightA < n) {
			q.push({abs(a[indexA].x - a[rightA].x), a[rightA].i});
		}
		it = prev(segmentsY.upper_bound({indexB, 1e9}));
		int leftB = it->first - 1, rightB = it->second + 1;
		if (0 <= leftB && leftB < n) {
			q.push({abs(b[indexB].x - b[leftB].x), b[leftB].i});
		}
		if (0 <= rightB && rightB < n) {
			q.push({abs(b[indexB].x - b[rightB].x), b[rightB].i});
		}
	}
	return result;
}

int main() {
//#ifndef ONLINE_JUDGE
//	freopen("input.in", "r", stdin);
//#endif
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &a[i].x, &a[i].y);
		a[i].i = i;
		b[i] = {a[i].y, a[i].x, i};
	}
	sort(a, a + n);
	sort(b, b + n);
	for (int i = 0; i < n; ++i)
		mpA[a[i].i] = i, mpB[b[i].i] = i;
	printf("%lld\n", prim(0));
	return 0;
}