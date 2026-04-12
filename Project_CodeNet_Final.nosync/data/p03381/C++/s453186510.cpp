#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int arr[n];
	vector<pair<int, int> > v;
	for (int i=0; i<n; i++) {
		scanf("%d", &arr[i]);
		v.push_back({arr[i], i});
	}
	sort(v.begin(), v.end());
	int ans[n];
	for (int i=0; i<n; i++) {
		if (i<n/2) ans[v[i].second]=v[n/2].first;
		else ans[v[i].second]=v[n/2-1].first;
	}
	for (int i=0; i<n; i++) printf("%d\n", ans[i]);
}
