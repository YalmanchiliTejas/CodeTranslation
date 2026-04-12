#include<bits/stdc++.h>
using namespace std;

using ll=long long; 

void solve(){
	int n;
	cin>>n;
	vector<int>h(n);
	for(int i=0; i<n; i++){
		cin>>h[i];
	}
	int maxv=-1;
	int cnt=0;
	for(int i=0; i<n; i++){
		if(maxv<=h[i]){
			cnt++;
		}
		maxv=max(maxv, h[i]);
	}
	cout<<cnt<<endl;
}

signed main(){
	//while(1)
	solve();
}