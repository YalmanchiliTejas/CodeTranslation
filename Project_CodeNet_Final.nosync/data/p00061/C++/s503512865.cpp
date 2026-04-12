#include<bits/stdc++.h>
#define rep(i,n)for(ll i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int, int>P;

map<int, int>mp;
vector<P>v;
int main() {
	int p, s;
	while (scanf("%d,%d", &p, &s), p) {
		v.push_back(P(s, p));
	}
	sort(v.begin(), v.end(), greater<>());
	int j = 1; mp[v[0].second] = 1;
	for (int i = 1; i < v.size(); i++) {
		if (v[i].first == v[i - 1].first)mp[v[i].second] = j;
		else mp[v[i].second] = ++j;
	}
	int q; while (cin >> q)cout << mp[q] << endl;
	return 0;
}

