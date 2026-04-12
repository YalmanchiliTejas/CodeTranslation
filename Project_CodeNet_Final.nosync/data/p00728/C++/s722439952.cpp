#include <bits/stdc++.h>
using namespace std;

int main() {
	while(true){
		int n;
		cin>>n;
		if(n==0) return 0;
		vector<int>v(n);
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		int sum=0;
		for(int i=0;i<n;i++){
			sum+=v[i];
		}
		sort(v.begin(),v.end());
		cout<<(sum-v[0]-v[n-1])/(n-2)<<endl;
	}
	return 0;
}
