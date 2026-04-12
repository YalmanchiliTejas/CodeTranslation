#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;
typedef pair<int,int> pii;
#define MAXN 100007
#ifdef LOCAL
#define DBG(...) printf(__VA_ARGS__)
#else
#define DBG(...) (void)(0)
#endif
int vis[MAXN];
int a[MAXN];
long long s[MAXN];
int nn;
int st=-1;
int main() {
#ifndef LOCAL
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#endif
	long long N;
	int x,y,m; cin >> N >> x >> m;
	y=x;
	memset(vis,0,sizeof vis);
	s[0]=0;
	for(nn=1; !vis[y]; nn++, y=1ll*y*y%m) {
		vis[y]=nn;
		a[nn]=y;
		s[nn]=s[nn-1]+a[nn];
		DBG("%d %d %d\n", nn, y, s[nn]);
	}
	nn--;
	st=vis[y];
	if(N>st) {
		long long ans=s[st-1]; N-=st-1;
		DBG("@st = %d %lld\n", st, ans);
		long long cnt=N/(nn-st+1);
		DBG("@cnt = %lld\n", cnt);
		long long rem=N%(nn-st+1);
		DBG("@rem = %lld\n", rem);
		ans=ans+cnt*(s[nn]-s[st-1])+(s[st-1+rem]-s[st-1]);
		DBG("@nn = %d, seg = %lld\n", nn, s[nn]-s[st-1]);
		cout << ans << '\n';
	} else {
		cout << s[N] << '\n';
	}
}
