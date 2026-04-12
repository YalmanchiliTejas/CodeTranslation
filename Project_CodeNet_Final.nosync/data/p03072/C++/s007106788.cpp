#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,ans = 1;
	cin >> n;
	vector<int> v(n);
	
	for(int i=0;i<n;++i) cin >> v[i];

	for(int i=1;i<n;++i){
		bool ok = true;
		for(int j=i-1;j>=0;--j){
			//cout << v[i] << ' ' << v[j] << '\n';
			if(v[i] < v[j]) ok = false;
		}

		if(ok) ++ans;
	}

	cout << ans << '\n';

	return 0;
}