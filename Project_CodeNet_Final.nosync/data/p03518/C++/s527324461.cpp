#include<bits/stdc++.h>
using namespace std;
long long a[605];
vector<int> vv;
signed main(){
	long long n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=1;j<n;j++){
			vv.push_back(1);
			for(int k=1;k<n;k++){
				swap(a[k-1],a[k]);
			}
			if(a[0]<a[n-1]){
				vv.push_back(n-1);
				swap(a[0],a[n-1]);
			}
		}
		vv.push_back(1);
		for(int j=1;j<n;j++){
			swap(a[j],a[j-1]);
		}
	}
	cout << vv.size()<<endl;
	for(auto x: vv){
		cout << x<<endl;
	}
}