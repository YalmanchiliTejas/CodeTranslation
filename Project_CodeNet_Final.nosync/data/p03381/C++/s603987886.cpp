#include<bits/stdc++.h>
using namespace std;

int n, a[200005], inv[200005];

vector<pair<int,int> > v;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		v.push_back({a[i],i});
	}
	sort(v.begin(), v.end());
	for(int i=0;i<n;i++) {
		inv[v[i].second] = i;
	}
	for(int i=1;i<=n;i++) {
		printf("%d\n",v[n/2-(inv[i] >= n/2)].first);
	}
}
