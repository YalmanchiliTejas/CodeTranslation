#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n;cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	vector<int> v;
	v.push_back(-a[0]);
	for(int i=1;i<n;i++){
		int idx=lower_bound(v.begin(),v.end(),-a[i]+1)-v.begin();
		if(idx==v.size()){
			v.push_back(-a[i]);
		}else{
			v[idx]=-a[i];
		}
	}
	cout<<v.size()<<endl;
	return 0;
}
