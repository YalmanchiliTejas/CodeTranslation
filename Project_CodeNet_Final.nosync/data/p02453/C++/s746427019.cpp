#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int n;cin>>n;
	vector<int>v;
	for(int i=0;i<n;i++){
		int vi;cin>>vi;
		v.push_back(vi);
	}
	cin>>n;
	for(int i=0;i<n;i++){
		int p;cin>>p;
		auto t = lower_bound(v.begin(),v.end(),p);
		cout<<t-v.begin()<<endl;
	}
	return 0;
}
