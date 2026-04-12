#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using P = pair<int, int>;
const int MX = 200005;
int n, x, y, xmax, ymin = 1e9, c[MX], u, e, l = 1e9;
long long ans;
P pr[MX*2];
int main(){
	scanf("%d", &n);
	rep(i,n){
		scanf("%d%d", &x, &y);
		if(x > y) swap(x,y);
		xmax = max(xmax, x);
		ymin = min(ymin, y);
		pr[i*2] = P(x,i);
		pr[i*2+1] = P(y,i);
	}
	sort(pr, pr+n*2);
	ans = (long long)(pr[n*2-1].first - ymin) * (xmax - pr[0].first);
	rep(i,n*2-2){
		if(++c[pr[i+1].second] == 1 && ++u == n){
			while(--c[pr[++e].second]);
			l = min(l, pr[i+1].first - pr[e].first);
			u--;
		}
	}
	ans = min(ans, (long long)(pr[n*2-1].first - pr[0].first) * l);
	printf("%lld\n", ans);
}
