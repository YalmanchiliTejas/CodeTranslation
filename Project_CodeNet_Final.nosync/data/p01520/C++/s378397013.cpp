#include <bits/stdc++.h>

#define ALL(a) (a).begin(), (a).end()
#define llong long long

using namespace std;

signed main(){
	
	int n, t, e; cin >> n >> t >> e;
	vector<int> x(n);
	for(int i = 0; i < n; i++) cin >> x[i];

	for(int i = 0; i < n; i++){
		for(int val = 1; val <= t; val++){
			int num = val * x[i];
			if(t - e <= num && num <= t + e){
				cout << i + 1 << endl;
				return 0;
			}
		}
	}


	cout << -1 << endl;
	return 0;
}


