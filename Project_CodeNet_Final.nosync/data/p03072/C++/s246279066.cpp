#include<iostream>
#include<algorithm>

using namespace std;
int main() {
	int n; cin>>n;
	int max_=0;
	int ans=0;
	for(int i=0; i<n; ++i) {
		int hi; cin>>hi;
		if(max_<=hi) {
			++ans; max_=hi;
		}
	}
	cout<<ans<<endl;

	return 0;
}