#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void read(int& x){ scanf("%d",&x); }
void read(ll& x){ scanf("%lld",&x); }
template<typename T,typename... Args>
void read(T& a,Args&... b){ read(a); read(b...); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define x first
#define y second

int n;
int x[200010];
int y[200010];

const ll inf = 1ll<<60;
ll F(){
	ll maxx=-inf, minx=inf;
	ll maxy=-inf, miny=inf;
	for(int i=1; i<=n; ++i){
		ll cx=x[i], cy=y[i];
		if(cx>cy) swap(cx, cy);
		maxx=max(maxx, cx);
		minx=min(minx, cx);
		
		maxy=max(maxy, cy);
		miny=min(miny, cy);
	}
	return (maxx-minx) * (maxy-miny);
}

pp d[400010];
map<int,int> cnt;
int dis;
void add(int x){ dis+=!cnt[x]++; }
void rem(int x){ dis-=!--cnt[x]; }
ll G(){
	for(int i=1; i<=n; ++i){
		d[i] = {x[i], i};
		d[n+i] = {y[i], i};
	}
	sort(d+1, d+2*n+1);
	ll co = d[2*n].x - d[1].x;
	ll ans = inf;
	int r=0;
	for(int i=1; i<=2*n; ++i){
		while(r<2*n && dis<n) add(d[++r].y);
		if(dis == n) ans = min(ans, 1ll*d[r].x-d[i].x);
		rem(d[i].y);
	}
	return co*ans;
}

int main()
{
	read(n);
	for(int i=1; i<=n; ++i) read(x[i], y[i]);
	printf("%lld\n", min(F(), G()));
    return 0;
}
