#include<bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
	int n;
	cin >> n;

	vector<ll> v(n);
	unordered_set<ll> s;
	for(auto& e : v) {
		cin >> e;
		s.insert(e);
	}
	sort(v.begin(), v.end());

	int ans = 0;
	for(int i=0;i<n;i++) {
		for(int j=i+1;j<n;j++) {
			int cnt = 2;
			ll nv = v[j] + (v[j] - v[i]);
			while(s.count(nv) > 0) {
				cnt++;
				nv += (v[j] - v[i]);
			}
			ans = max(ans, cnt);
		}
	}
	cout << ans << endl;

	return 0;
}

