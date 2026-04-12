#include <bits/stdc++.h>
using namespace std;

signed main(){
	int n,p[200];
	vector<int> ans;
	cin >> n;
	for(int i = 0;i < n;i++) cin >> p[i];
	for(int i = 0;i <= n;i++){
		for(int j = 0;j < n;j++){
			bool flag = true;
			for(int k = 0;k < n;k++){
				if(p[k] != k) flag = false;
			}
			if(flag){
				cout << ans.size() << endl;
				for(int v : ans) cout << v << endl;
				return 0;
			}
			if(j != n - 1 && p[0] < p[n - 1]){
				ans.push_back(n - 1);
				swap(p[0],p[n - 1]);
			}
			ans.push_back(1);
			for(int k = 1;k < n;k++) swap(p[k],p[k - 1]);
		}
	}
	return 0;
}