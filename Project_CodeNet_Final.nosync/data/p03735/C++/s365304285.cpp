#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<int>;
const int maxn = 305, mlg = 18, rt = 1<<10, mod = 1e9 + 7;
int good[maxn][maxn][maxn], dp[maxn][maxn][maxn], n, m;
vector<pair<int, int>> a;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	int al = 1<<30, ar = 0, bl = 1<<30, br = 0;
	for(int x, y, i = 0; i < n; i++) {
		cin >> x >> y;
		if(x < y) swap(x, y);
		al = min(x, al);
		ar = max(x, ar);
		bl = min(y, bl);
		br = max(y, br);
		a.pb({x, i});
		a.pb({y, i});
	}
	//cout << al << " " << ar << " " << bl << " " << br << '\n';
	ll ans = (ar-al) * 1ll * (br-bl);
	sort(all(a));
	al = min(al, bl), ar = max(br, ar);
	map<int, int> cnt;
	//for(auto i : a) cout << i.first << " - " << i.second << '\n';
	for(int i = 0, j = 0; i+1 < a.size(); i++) {
		cnt[a[i].second]++;
		while(cnt[a[j].second]>1) cnt[a[j++].second]--;
		//cout << j << " " << i << '\n';
		if(cnt.size() == n && j > 0) ans = min(ans, (ar - al) * 1ll * (a[i].first - a[j].first));
	}
	cout << ans;
}
