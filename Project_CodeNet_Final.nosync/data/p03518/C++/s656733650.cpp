#include<bits/stdc++.h>
using namespace std;
long long inp[205];
vector<int> ans;
signed main(){
	long long n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> inp[i];
	}
	for(int i=0;i<n;i++){
		for(int j=1;j<n;j++){
			ans.push_back(1);
			for(int k=1;k<n;k++){
				swap(inp[k-1],inp[k]);
			}
			if(inp[0]<inp[n-1]){
				ans.push_back(n-1);
				swap(inp[0],inp[n-1]);
			}
		}
		ans.push_back(1);
		for(int j=1;j<n;j++){
			swap(inp[j],inp[j-1]);
		}
	}
	cout << ans.size()<<endl;
	for(auto x: ans){
		cout << x<<endl;
	}
}