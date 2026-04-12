#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	vector<int> h(n);
	int m=0;
	int ans=0;
	for(int i=0;i<n;i++){
		cin>>h[i];
	}
	for(int i=0;i<n;i++){
		if(h[i]>=m){
			m = h[i];
			ans++;
		}
	}
	cout<<ans<<endl;
}
