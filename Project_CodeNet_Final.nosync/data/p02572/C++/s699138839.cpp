// timusg
#include <iostream>
#include <bits/stdc++.h>

int main(){
	using namespace std;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int mod = 1e9 + 7;
	int cas = 1;
	//cin >> cas;
	while(cas--){
		int64_t n, sum = 0, res = 0;
		cin >> n;
		int64_t a[n];

		for(int64_t i=0; i<n; ++i){
			cin >> a[i];
			sum += a[i];
			sum %= mod;
		}

		for(int i=0; i<n; ++i){
			sum -= a[i];
			if(sum < 0) sum += mod;

			res += a[i]*sum;
			res %= mod;
		}

		cout << res << "\n";
	}
	
	return 0;
}  

