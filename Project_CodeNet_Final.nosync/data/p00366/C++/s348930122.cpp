#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int n, mx = 0, a[111111], res = 0;
	vector<int> v;
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>a[i];
		mx = max(mx, a[i]);
	}
	for(int i = 1; i <= mx; i++){
		if(mx % i == 0) v.push_back(i);
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < v.size(); j++){
			if(v[j] >= a[i]){
				res += v[j] - a[i];
				break;
			}
		}
	}
	cout<<res<<endl;
}
