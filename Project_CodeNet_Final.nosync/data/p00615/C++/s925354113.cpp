#include<bits/stdc++.h>
#define rep(i,n)for(int i=0;i<n;i++)
using namespace std;

int main() {
	int n, m;
	while (cin >> n >> m, n || m) {
		vector<int>v;
		v.push_back(0);
		rep(i, n + m) {
			int a; cin >> a;
			v.push_back(a);
		}
		sort(v.begin(), v.end());
		vector<int>ans;
		rep(i, n + m) {
			ans.push_back(v[i + 1] - v[i]);
		}
		sort(ans.begin(), ans.end(), greater<>());
		cout << ans[0] << endl;
	}
}