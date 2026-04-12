#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	if(n%2==0){
		for(int i=n;i>0;i-=2)
		cout<<a[i]<<" ";
		for(int i=1;i<n;i+=2)
		cout<<a[i]<<" ";
	}
	else{
		for(int i=n;i>0;i-=2)
		cout<<a[i]<<" ";
		for(int i=2;i<n;i+=2)
		cout<<a[i]<<" ";
	}
	cout<<"\n";
	return 0;
}