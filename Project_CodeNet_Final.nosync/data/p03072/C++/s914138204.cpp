#include <iostream>
#include<vector>
using namespace std;

int main() {
	int n;cin>>n;
	vector<int> h(n);
	for(int i=0;i<n;i++){
		cin>>h[i];
	}
	int ans=1;
	int maxh=h[0];
	for(int i=1;i<n;i++){
		if(h[i]>=maxh){
			maxh=h[i];
			ans++;
		}
	}
	cout<<ans<<endl;

	return 0;
}
