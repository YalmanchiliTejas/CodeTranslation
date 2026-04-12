#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){

	int n; cin >> n;
	vector<int> x(n+1, 0);

	map<int, int> mp;

	mp[0] = 0;
	for(int i = 0;i < n;i++){
		cin >> x[i+1]; x[i+1] += x[i];
		mp[x[i+1]] = i+1;
	}

	int ans = 0;
	for(int i = 0;i < n;i++){
		ans = max(ans, mp[x[i]] - i);
	}

	cout << ans << endl;
	return 0;
}

