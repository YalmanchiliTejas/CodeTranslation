#include <bits/stdc++.h>

using namespace std;

int main(){
	while(true){
		int n; cin >> n;
		if(n==0)break;

		vector<int> j(n);
		for(int i = 0; i < n; ++i)cin >> j[i];
		sort(j.begin(), j.end());
		int ans = 0;
		for(int i = 1; i < n-1; ++i){
			ans += j[i];
		}
		ans /= j.size()-2;
		cout << ans << endl;
	}
	return 0;
}