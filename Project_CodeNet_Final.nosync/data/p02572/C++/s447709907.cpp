#include<bits/stdc++.h>

using namespace std;

#define int long long
#define nl "\n"
#define sp " "

const int mod = 1e9 + 7;

signed main(){
	int n; cin >> n; vector<int> v(n), c(n);
	for (int i = 0; i < n; i++){
		cin >> v[i]; c[i] = v[i];
	}
	int sum = 0, ans = 0; unordered_map<int, int> mp;
	for (int i = c.size() - 1; i > 0; i--){
		sum += c[i];
		mp.insert(make_pair(i, sum));
	}
	for (int i = 0; i < v.size() - 1; i++){
		ans += ((v[i] % mod) * (mp[i+1] % mod));
		ans = ans % mod;
	}
	cout << ans;
}
