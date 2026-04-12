#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define maxn 100100
#define LL long long
using namespace std;
int n;
int fa[maxn];

void init() {
	for(int i = 0; i <= n; i++) {
		fa[i] = i;
	}
}

int find(int x) {
	return (fa[x] == x ? x : fa[x] = find(fa[x]));
}

bool connect(int a, int b) {
	int x = find(a);
	int y = find(b);
	if(x != y) {
		fa[x] = y;
		return true;
	}
	else {
		return false;
	}
}

struct Node {
	int x, y;
	int sign;
} node[maxn];

struct Segment {
	int a, b;
	int dis;
};

bool cmp1(Node a, Node b) {
	return a.x < b.x;
}

bool cmp2(Node a, Node b) {
	return a.y < b.y;
}

bool cmp(Segment x, Segment y) {
	return x.dis < y.dis;
}

int main() {
	while(~scanf("%d", &n)) {
		init();
		for(int i = 1; i <= n; i++) {
			int _x, _y;
			scanf("%d%d", &_x, &_y);
			node[i].x = _x;
			node[i].y = _y;
			node[i].sign = i;
		}
		vector<Segment> vec;
		sort(node + 1, node + 1 + n, cmp1);
		for(int i = 2; i <= n; i++) {
			Segment segment;
			segment.a = node[i - 1].sign;
			segment.b = node[i].sign;
			segment.dis = node[i].x - node[i - 1].x;
			vec.push_back(segment);
		}
		sort(node + 1, node + 1 + n, cmp2);
		for(int i = 2; i <= n; i++) {
			Segment segment;
			segment.a = node[i - 1].sign;
			segment.b = node[i].sign;
			segment.dis = node[i].y - node[i - 1].y;
			vec.push_back(segment);
		}
		sort(vec.begin(), vec.end(), cmp);
		LL ans = 0;
		for(int i = 0; i < vec.size(); i++) {
			if(connect(vec[i].a, vec[i].b)) {
				ans += vec[i].dis;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}