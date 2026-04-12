#include<bits/stdc++.h>
using namespace std;	
int main(){
	int n; cin>>n;
	vector<int> a(n);
	for(int i =0; i<n; i++){
		cin>>a[i];
	}
	int ans = 0;
	int t = 0;
	for(int i =0; i < n; i++){
		if(a[i] >= t){
			ans++;
			t = a[i];
		}
	}
	cout<<ans;
	return 0;
}
