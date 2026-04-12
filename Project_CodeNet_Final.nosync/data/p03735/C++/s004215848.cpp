#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const int MAXN = 200005;
using lint = long long;
using pi = pair<int, int>;

int n, chk[MAXN];
vector<pi> v;
pi a[MAXN];

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%d %d",&a[i].first,&a[i].second);
		if(a[i].first > a[i].second) swap(a[i].first, a[i].second);
	}
	int sx = 1e9, sy = 1e9, ex = -1e9, ey = -1e9;
	for(int i=0; i<n; i++){
		sx = min(sx, a[i].first);
		sy = min(sy, a[i].second);
		ex = max(ex, a[i].first);
		ey = max(ey, a[i].second);
		v.push_back(pi(a[i].first, i));
		v.push_back(pi(a[i].second, i));
	}
	lint ans = 1ll * (ex - sx) * (ey - sy);
	sort(v.begin(), v.end());
	int e = 0, gap = 1e9, cnt = 0;
	for(int i=0; i<v.size(); i++){
		while(e < v.size() && cnt < n){
			if(!chk[v[e].second]){
				cnt++;
			}
			chk[v[e].second]++;
			e++;
		}
		if(cnt == n) gap = min(gap, v[e-1].first - v[i].first);
		chk[v[i].second]--;
		if(chk[v[i].second] == 0) cnt--;
	}
	ans = min(ans, 1ll * (v.back().first - v[0].first) * gap);
	cout << ans << endl;
}
