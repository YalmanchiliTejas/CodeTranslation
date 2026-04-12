#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	int n;
	while(cin>>n,n){
		int a[n];
		for(int i=0;i<n;i++)cin>>a[i];
		sort(a,a+n);
		for(int i=2;i<n-1;i++)a[1]+=a[i];
		cout<<a[1]/(n-2)<<endl;
	}	

}