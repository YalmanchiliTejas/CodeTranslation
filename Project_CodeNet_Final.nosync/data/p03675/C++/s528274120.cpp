#include<iostream>
using namespace std;
int a[200007];
int main(){
	int n;
	int i,j,k;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	for(i=0,j=n-1;j>=0;i++,j-=2){
		cout<<a[j];
		if(i!=n-1)cout<<" ";
		else cout<<endl;
	}
	for(j=n%2;j<n;j+=2){
		cout<<a[j];
		if(i!=n-1)cout<<" ";
		else cout<<endl;
	}
	return 0;
}
		
