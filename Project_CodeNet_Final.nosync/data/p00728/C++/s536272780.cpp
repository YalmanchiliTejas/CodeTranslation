#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int n,a[1000],c;
	while(true){
		cin>>n;
		if(n==0){
			break;
		}
		c=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n);
		for(int i=1;i<n-1;i++){
			c+=a[i];
		}
		cout<<c/(n-2)<<endl;
	}
	return 0;
}
