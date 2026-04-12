#include <iostream>
using namespace std;

int main() {
	int n,i;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++)cin>>a[i];
	if(n%2==0){
	    for(i=n-1;i>=0;i-=2){
	        cout<<a[i]<<" ";
	    }
	    for(i=0;i<n;i+=2){
	        cout<<a[i]<<" ";
	    }
	    cout<<endl;
	}
	else{
	    for(i=n-1;i>=0;i-=2){
	        cout<<a[i]<<" ";
	    }
	    for(i=1;i<n;i+=2){
	        cout<<a[i]<<" ";
	    }
	    cout<<endl;
	}
	
	return 0;
}