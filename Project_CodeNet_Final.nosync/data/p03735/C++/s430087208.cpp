#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cassert>
#include<algorithm>
#include<queue>
#define llong long long
using namespace std;

const int N = 2e5;
const llong INF = 1000000000000000000ll;
struct Element
{
	llong x,y;
	bool operator <(const Element &arg) const {return x>arg.x;}
} a[N+3];
priority_queue<Element> pq;
int n;
llong mx,mn,mxx,mny;
llong ans;

void solve1()
{
	for(int i=1; i<=n; i++) pq.push(a[i]);
	llong cur = mxx,cury = INF;
	for(int i=1; i<n; i++)
	{
		Element tmp = pq.top(); pq.pop();
		cur = max(cur,tmp.y); cury = min(cury,tmp.y);
		ans = min(ans,(mx-mn)*(cur-min(pq.top().x,cury)));
//		printf("%lld %lld %lld\n",tmp.x,cury,cur);
	}
}

void solve2()
{
	ans = min(ans,(mx-mny)*(mxx-mn));
}

int main()
{
	scanf("%d",&n); mn = mny = INF;
	for(int i=1; i<=n; i++)
	{
		scanf("%lld%lld",&a[i].x,&a[i].y);
		if(a[i].x>a[i].y) {swap(a[i].x,a[i].y);}
		mx = max(mx,a[i].y); mxx = max(mxx,a[i].x);
		mn = min(mn,a[i].x); mny = min(mny,a[i].y);
	}
	ans = INF;
	solve1();
	solve2();
	printf("%lld\n",ans);
	return 0;
}
/*
11
10 19
4 7
20 28
7 18
2 4
3 9
4 22
14 24
2 6
6 13
14 20
*/