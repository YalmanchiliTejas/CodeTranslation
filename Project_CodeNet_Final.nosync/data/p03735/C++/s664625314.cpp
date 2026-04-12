// luogu-judger-enable-o2
#include <algorithm>
#include <assert.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

typedef long long ll;

const int MX = 200005;
const int oo = 1231231231;

template <typename T> void read(T &x)
{
	x = 0; char c = getchar(); bool f = 0;
	while(!isdigit(c) && c!='-') c = getchar();
	if(c == '-') f = 1, c = getchar();
	while(isdigit(c)) x = x*10+c-'0', c = getchar();
	if(f) x = -x;
}

struct NODE
{
	int x, y;
	
	bool operator < (const NODE& t) const {return x < t.x;}
};

int n;
NODE pot[MX];
int ymn[MX];

int main()
{
	read(n);
	for(int i=1; i<=n; i++)
	{
		read(pot[i].x), read(pot[i].y);
		if(pot[i].y > pot[i].x) swap(pot[i].x, pot[i].y);
	}
	sort(pot+1, pot+n+1);
	int xmn = pot[1].x, ymx = 0, xmx = 0;
	ymn[0] = +oo;
	for(int i=1; i<=n; i++) ymn[i] = min(ymn[i-1], pot[i].y), ymx = max(ymx, pot[i].y);
	ll ans = 1ll * (pot[n].x-xmn) * (ymx-ymn[n]);
	for(int i=n; i>=2; i--)
	{
		ymx = max(ymx, pot[i].x);
		xmn = min(xmn, pot[i].y);
		xmx = max(xmx, pot[i].y);
		ans = min(ans, 1ll*(max(xmx, pot[i-1].x)-xmn)*(ymx-ymn[i-1]));
	}
	printf("%lld\n", ans);
	return 0;
}