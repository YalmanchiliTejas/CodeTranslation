#include <bits/stdc++.h>
using namespace std;

struct Pos{ int x, y, i; };

struct E{
	int s, e, x;
	bool operator<(const E &oth) const {
		return x < oth.x;
	}
};

int n, p[100010], ans;
Pos a[100010];
vector<E> el;

int fnd(int x){ return p[x] = (x == p[x] ? x : fnd(p[x])); }
void uni(int x, int y){ p[fnd(x)] = fnd(y); }

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d%d", &a[i].x, &a[i].y);
		a[i].i = i;
	}
	sort(a + 1, a + n + 1, [](Pos a, Pos b){ return a.x < b.x; });
	for(int i = 2; i <= n; i++){
		el.push_back({a[i - 1].i, a[i].i, a[i].x - a[i - 1].x});
	}
	sort(a + 1, a + n + 1, [](Pos a, Pos b){ return a.y < b.y; });
	for(int i = 2; i <= n; i++){
		el.push_back({a[i - 1].i, a[i].i, a[i].y - a[i - 1].y});
	}
	sort(el.begin(), el.end());
	for(int i = 1; i <= n; i++) p[i] = i;
	for(auto &i : el){
		if(fnd(i.s) == fnd(i.e)) continue;
		ans += i.x;
		uni(i.s, i.e);
	}
	printf("%d\n", ans);
}