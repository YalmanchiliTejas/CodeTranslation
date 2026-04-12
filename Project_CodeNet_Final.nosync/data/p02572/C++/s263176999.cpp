#include <bits/stdc++.h>
#define int long long

using namespace std;

int Mod = 1e9+7;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	int sum_ = 0;
	vector<int> v(n);	
	vector<int> pref(n+1);

	for(int i = 0 ; i < n; i++){
		int t; cin >> t;
		v[i] = t; sum_ += t;
		pref[i+1] = pref[i] + t;
	}

	int ans = 0;

	for(int i = 0 ; i < n - 1; i++){
		ans += ((v[i] % Mod) * ((sum_  - pref[i + 1])%Mod))%Mod;
		ans %= Mod;
	}

	cout << ans;


  return 0;
}
