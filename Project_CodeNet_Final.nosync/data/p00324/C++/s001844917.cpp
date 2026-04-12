#include<bits/stdc++.h>
#define rep(i,n)for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;

int main() {
	int n; scanf("%d", &n);
	map<ll, vector<int>>mp;
	mp[0].push_back(0);
	ll s = 0;
	rep(i, n) {
		ll a; scanf("%lld", &a);
		s += a;
		mp[s].push_back(i + 1);
	}
	int Max = 0;
	for (auto&p : mp) {
		Max = max(Max, p.second.back() - p.second.front());
	}
	printf("%d\n", Max);
}