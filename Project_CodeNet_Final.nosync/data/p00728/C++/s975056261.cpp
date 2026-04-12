#include <iostream>
using namespace std;
int main(){
	while(true){
		int n,sum=0,mx=-1,mn=100000;
		cin >> n;
		if(n==0) break;
		for(int i=0;i<n;i++){
			int s;
			cin >> s;
			mn=min(mn,s);
			mx=max(mx,s);
			sum+=s;
		}
		cout << (sum-mn-mx)/(n-2) << endl;
	}
	return 0;
}