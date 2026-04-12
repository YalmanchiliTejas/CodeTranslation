#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	vector<int> a(n), b;
	for(int i=0;i<n;i++){
		cin >> a[i];
		b.push_back(i);
	}

	sort(b.begin(),b.end(),[&](int &p, int &q){
		return a[p]<a[q];
	});
	vector<int> ans(n);
	for(int i=0;i<n;i++){
		if(i<n/2){
			ans[b[i]] = a[b[n/2]];
		}
		else{
			ans[b[i]] = a[b[n/2-1]];
		}
	}

	for(int i=0;i<n;i++){
		cout << ans[i] << endl;
	}
	return 0;
}
