#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int n;
	while(cin>>n && n!=0){
		vector <int> a;
		for(int i=0;i<n;i++){
			int b;
			cin>>b;
			a.push_back(b);
		}
		sort(a.begin(),a.end());

		int ans=0;
		for(int i=0;i<n-2;i++){
			ans+=a[i+1];
		}
		cout<<ans/(n-2)<<endl;
	}
	return 0;
}