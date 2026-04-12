#include<bits/stdc++.h>
#define rep(i,n)for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;

ll d[200001];
int main() {
	int n; scanf("%d", &n);
	unordered_map<ll, vector<int>>mp;
	mp[0].push_back(0);
	rep(i, n) {
		scanf("%lld", &d[i + 1]);
		d[i + 1] += d[i];
		mp[d[i + 1]].push_back(i + 1);
	}
	int Max = 0;
	for (auto&p : mp) {
		Max = max(Max, *p.second.rbegin() - *p.second.begin());
	}
	printf("%d\n", Max);
}