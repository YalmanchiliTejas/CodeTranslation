#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define fi first
#define se second
#define FOR(a, b, c) for(int a = b; a <= c; ++a)
#define mp make_pair
const int N=1e5+5;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
int n, pr[N];
vector<ii> xx, yy;
priority_queue<iii, vector<iii>, greater<iii> > pq;
int find(int i) {
	return (pr[i] == i) ? i : (pr[i] = find(pr[i]));
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin >> n;
    FOR(i, 1, n) {
    	int x, y; cin >> x >> y;
    	xx.pb(mp(x, i)); yy.pb(mp(y, i));
	}
	sort(xx.begin(), xx.end()); sort(yy.begin(), yy.end());
	FOR(i, 1, xx.size() - 1)	{
		pq.push(mp(xx[i].fi - xx[i - 1].fi, mp(xx[i].se, xx[i - 1].se)) );
	}
	FOR(i, 1, yy.size() - 1)
		pq.push(mp(yy[i].fi - yy[i - 1].fi, mp(yy[i].se, yy[i - 1].se)));
	int ans = 0;
	FOR(i, 1, n) 	pr[i] = i;
	while(!pq.empty())	{
		int u = pq.top().se.fi, v = pq.top().se.se, uv = pq.top().fi; pq.pop();
		if(find(u) != find(v))	{
			pr[find(u)] = find(v);
			ans += uv;
		}
	}
	cout << ans;
} 
