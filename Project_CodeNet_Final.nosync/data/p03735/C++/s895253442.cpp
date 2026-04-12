#include<bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<pair<int,int>> a(n);
	for (int i = 0;i < n;i++) {
		cin >> a[i].first >> a[i].second;
		if (a[i].first > a[i].second) swap(a[i].first,a[i].second);
	}
	sort(a.begin(),a.end());
	int l = a[0].second,r = a[0].second;
	for (int i = 1;i < n;i++) {
		l = min(l,a[i].second);
		r = max(r,a[i].second);
	}
	long long ans = 1ll * (a[n-1].first - a[0].first) * (r - l);
	long long len = r - a[0].first;
	l = a[n-1].second;r = a[n-1].first;
	for (int i = 0;i <= n;i++) {
		ans = min(ans,len * (r - (i == n ? l : min(l,a[i].first))));
		if (i == n) break;
		l = min(l,a[i].second);
		r = max(r,a[i].second);
	}
	cout << ans;
}